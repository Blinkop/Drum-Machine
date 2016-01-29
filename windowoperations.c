#include "windowoperations.h"

bool DMinitialize(SDL_Window** window, GUI_elements* elements, SDL_Renderer** renderer, FramesChange* frames)
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		fprintf(stderr, "Failed to load Drum Machine: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
		{
			fprintf(stderr, "Audio init error: %s", Mix_GetError());
		}
		if (TTF_Init() != 0)
		{
			fprintf(stderr, "TTF Failed: %s", TTF_GetError());
		}
		*window = SDL_CreateWindow("Drum Machine", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (*window == NULL)
		{
			fprintf(stderr, "Failed to load Drum Machine: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			/*---Scene Behind Texture---*/
			elements->backBround.frame = loadTexture("Frames\\Texture.png", *renderer);			
			SDL_RenderClear(*renderer);
			/*---GUI Textures---*/
			loadImageSource(elements, *renderer, frames);
			BlitGUI(elements, *renderer);
			/*---Update DM---*/
			SDL_RenderPresent(*renderer);
		}
	}
	return success;
}
bool loadImageSource(GUI_elements* elements, SDL_Renderer* renderer, FramesChange* frames)
{
	bool success = true;
	frames->pad = loadTextureBMP("Frames\\Pad.bmp", renderer);
	frames->padPressed = loadTextureBMP("Frames\\PadPressed.bmp", renderer);
	frames->Clear = loadTextureBMP("Frames\\Clear.bmp", renderer);
	frames->ClearPressed = loadTextureBMP("Frames\\ClearPressed.bmp", renderer);
	frames->Record = loadTextureBMP("Frames\\Record.bmp", renderer);
	frames->RecordPressed = loadTextureBMP("Frames\\RecordPressed.bmp", renderer);
	frames->Play = loadTextureBMP("Frames\\Play.bmp", renderer);
	frames->PlayPressed = loadTextureBMP("Frames\\PlayPressed.bmp", renderer);
	frames->Pause = loadTextureBMP("Frames\\Pause.bmp", renderer);
	frames->PausePressed = loadTextureBMP("Frames\\PausePressed.bmp", renderer);
	frames->Stop = loadTextureBMP("Frames\\Stop.bmp", renderer);
	frames->StopPressed = loadTextureBMP("Frames\\StopPressed.bmp", renderer);
	frames->ToStart = loadTextureBMP("Frames\\ToStart.bmp", renderer);
	frames->ToStartPressed = loadTextureBMP("Frames\\ToStartPressed.bmp", renderer);
	frames->Quantize = loadTextureBMP("Frames\\Quantize.bmp", renderer);
	frames->QuantizePressed = loadTextureBMP("Frames\\QuantizePressed.bmp", renderer);
	
	elements->padsFrame.frame = loadTextureBMP("Frames\\PadsFrame.bmp", renderer);
	elements->functionalFrame.frame = loadTextureBMP("Frames\\FunctionalFrame.bmp", renderer);
	elements->RecordButton.frame = loadTextureBMP("Frames\\Record.bmp", renderer);
	elements->PlayButton.frame = loadTextureBMP("Frames\\Play.bmp", renderer);
	elements->PauseButton.frame = loadTextureBMP("Frames\\Pause.bmp", renderer);
	elements->StopButton.frame = loadTextureBMP("Frames\\Stop.bmp", renderer);
	elements->ToStartButton.frame = loadTextureBMP("Frames\\ToStart.bmp", renderer);
	elements->ClearButton.frame = loadTextureBMP("Frames\\Clear.bmp", renderer);
	elements->QuantizeButton.frame = loadTextureBMP("Frames\\Quantize.bmp", renderer);

	elements->barClock.font = TTF_OpenFont("Frames\\Caviar-Dreams\\CaviarDreams.ttf", 28);

	for (Uint8 i = 0; i < 16; i++)
	{
		elements->pad[i].sound = NULL;
		elements->pad[i].pad = loadTextureBMP("Frames\\Pad.bmp", renderer);
	}

	return success;
}
void DMclose(SDL_Window** window, GUI_elements** elements)
{
	SDL_DestroyWindow(*window);
	free(*elements);
	SDL_Quit();
}
SDL_Texture* updatePadButton(SDL_Renderer* renderer, SDL_Texture* frame)
{
	SDL_Texture* texture = frame;
	if (texture == NULL) fprintf(stderr, "Frame error: %s", SDL_GetError());
	return texture;
}
SDL_Texture* loadTexture(char* const path, SDL_Renderer* renderer)
{
	SDL_Texture* texture = NULL;
	SDL_Surface* textureSurface = IMG_Load(path);
	int imgFlags = IMG_INIT_PNG;

	SDL_SetRenderDrawColor(renderer, 0x0f, 0x1f, 0xef, 0xff);

	if (!(IMG_Init(imgFlags) & imgFlags))
		fprintf(stderr, "1)Texture error: %s\n", SDL_GetError());
	if (textureSurface == NULL)
		fprintf(stderr, "2)Texture error: %s\n", SDL_GetError());
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer, textureSurface);
		if (texture == NULL)
			fprintf(stderr, "3)Texture error: %s\n", SDL_GetError());	
		SDL_FreeSurface(textureSurface);
	}
	return texture;
}
SDL_Texture* loadTextureBMP(char* const path, SDL_Renderer* renderer)
{
	SDL_Texture* texture = NULL;
	SDL_Surface* surface = SDL_LoadBMP(path);
	if (surface == NULL)
		fprintf(stderr, "%s", SDL_GetError());
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		if (texture == NULL)
			fprintf(stderr, "%s", SDL_GetError());
		SDL_FreeSurface(surface);
	}
	return texture;
}
void BlitGUI(GUI_elements* elements, SDL_Renderer* renderer)
{
	Uint8 padsSpace = 20;
	Uint8 ButtonWidth = 38;
	Uint8 ButtonSpace = 10;
	elements->functionalFrame.rect = CreateRect(SCREEN_HEIGHT / 10, 2 * SCREEN_WIDTH / 3, SCREEN_WIDTH / 3, 0);
	elements->channelsFrame.rect = CreateRect(SCREEN_HEIGHT / 10, 2 * SCREEN_WIDTH / 3,
		SCREEN_WIDTH / 3, SCREEN_HEIGHT - SCREEN_HEIGHT / 10);
	elements->padsFrame.rect = CreateRect(SCREEN_HEIGHT - elements->channelsFrame.rect.h - elements->functionalFrame.rect.h,
		2 * SCREEN_WIDTH / 3, SCREEN_WIDTH / 3, SCREEN_HEIGHT / 10);
	/*---OMG GRAPHICS STARTS FROM HERE---*/
	/*---First line Pads---*/
	elements->pad[0].rect = CreateRect((elements->padsFrame.rect.h - padsSpace * 5) / 4, (elements->padsFrame.rect.w - padsSpace * 5) / 4,
		elements->padsFrame.rect.x + padsSpace, elements->padsFrame.rect.y + padsSpace);
	for (Uint8 i = 1; i < 4; i++)
	{
		elements->pad[i].rect = CreateRect((elements->padsFrame.rect.h - padsSpace * 5) / 4,
			(elements->padsFrame.rect.w - padsSpace * 5) / 4,
			elements->padsFrame.rect.x + (i + 1) * padsSpace + i * elements->pad[0].rect.w, elements->padsFrame.rect.y + padsSpace);
		elements->pad[i+4].rect = CreateRect((elements->padsFrame.rect.h - padsSpace * 5) / 4,
			(elements->padsFrame.rect.w - padsSpace * 5) / 4,
			elements->padsFrame.rect.x + (i + 1) * padsSpace + i * elements->pad[0].rect.w,
			elements->padsFrame.rect.y + 2 * padsSpace + elements->pad[0].rect.h);
		elements->pad[i+8].rect = CreateRect((elements->padsFrame.rect.h - padsSpace * 5) / 4,
			(elements->padsFrame.rect.w - padsSpace * 5) / 4,
			elements->padsFrame.rect.x + (i + 1) * padsSpace + i * elements->pad[0].rect.w,
			elements->padsFrame.rect.y + 3 * padsSpace + 2 * elements->pad[0].rect.h);
		elements->pad[i+12].rect = CreateRect((elements->padsFrame.rect.h - padsSpace * 5) / 4,
			(elements->padsFrame.rect.w - padsSpace * 5) / 4,
			elements->padsFrame.rect.x + (i + 1) * padsSpace + i * elements->pad[0].rect.w,
			elements->padsFrame.rect.y + 4 * padsSpace + 3 * elements->pad[0].rect.h);
	}
	/*---Second line Pads---*/
	elements->pad[4].rect = CreateRect((elements->padsFrame.rect.h - padsSpace * 5) / 4, (elements->padsFrame.rect.w - padsSpace * 5) / 4,
		elements->padsFrame.rect.x + padsSpace,
		elements->padsFrame.rect.y + 2 * padsSpace + elements->pad[0].rect.h);
	/*---Third line Pads---*/
	elements->pad[8].rect = CreateRect((elements->padsFrame.rect.h - padsSpace * 5) / 4, (elements->padsFrame.rect.w - padsSpace * 5) / 4,
		elements->padsFrame.rect.x + padsSpace,
		elements->padsFrame.rect.y + 3 * padsSpace + 2 * elements->pad[0].rect.h);
	/*---Forth line Pads---*/
	elements->pad[12].rect = CreateRect((elements->padsFrame.rect.h - padsSpace * 5) / 4, (elements->padsFrame.rect.w - padsSpace * 5) / 4,
		elements->padsFrame.rect.x + padsSpace,
		elements->padsFrame.rect.y + 4 * padsSpace + 3 * elements->pad[0].rect.h);
	/*---Buttons---*/
	elements->StopButton.rect = CreateRect(elements->functionalFrame.rect.h / 3, ButtonWidth,
		elements->functionalFrame.rect.x + ButtonSpace, elements->functionalFrame.rect.h / 3);
	elements->PlayButton.rect = CreateRect(elements->functionalFrame.rect.h / 3, ButtonWidth,
		elements->StopButton.rect.x + ButtonWidth + ButtonSpace, elements->functionalFrame.rect.h / 3);
	elements->ToStartButton.rect = CreateRect(elements->functionalFrame.rect.h / 3, ButtonWidth,
		elements->PlayButton.rect.x + ButtonWidth + ButtonSpace, elements->functionalFrame.rect.h / 3);
	elements->RecordButton.rect = CreateRect(elements->functionalFrame.rect.h / 3, ButtonWidth,
		elements->ToStartButton.rect.x + ButtonWidth + ButtonSpace, elements->functionalFrame.rect.h / 3);
	elements->ClearButton.rect = CreateRect(elements->functionalFrame.rect.h / 3, ButtonWidth,
		elements->RecordButton.rect.x + ButtonWidth + ButtonSpace, elements->functionalFrame.rect.h / 3);
	elements->QuantizeButton.rect = CreateRect(elements->functionalFrame.rect.h / 3, ButtonWidth,
		SCREEN_WIDTH - ButtonWidth - ButtonWidth, elements->functionalFrame.rect.h / 3);
	/*---TTF---*/
	elements->barClock.rect = CreateRect(SCREEN_HEIGHT / 10,
		SCREEN_WIDTH / 8, elements->ClearButton.rect.x + ButtonWidth + 2 * ButtonSpace, 0);
	elements->barClock.color = CreateColor(0, 0, 0, 255);
	elements->barClock.bar_clock = NULL;
	elements->bpm_control.rect = CreateRect(SCREEN_HEIGHT / 10, SCREEN_WIDTH / 11,
		elements->barClock.rect.x + elements->barClock.rect.w + ButtonSpace * 3, 0);
	elements->bpm_control.BPMtexture = NULL;
	
	SDL_RenderCopy(renderer, elements->functionalFrame.frame, 0, &elements->functionalFrame.rect);
	SDL_RenderCopy(renderer, elements->padsFrame.frame, 0, &elements->padsFrame.rect);
	SDL_RenderCopy(renderer, elements->StopButton.frame, 0, &elements->StopButton.rect);
	SDL_RenderCopy(renderer, elements->PlayButton.frame, 0, &elements->PlayButton.rect);
	SDL_RenderCopy(renderer, elements->ToStartButton.frame, 0, &elements->ToStartButton.rect);
	SDL_RenderCopy(renderer, elements->RecordButton.frame, 0, &elements->RecordButton.rect);
	SDL_RenderCopy(renderer, elements->ClearButton.frame, 0, &elements->ClearButton.rect);
	SDL_RenderCopy(renderer, elements->QuantizeButton.frame, 0, &elements->QuantizeButton.rect);
	SDL_RenderCopy(renderer, SDL_CreateTextureFromSurface(renderer,
		TTF_RenderText_Solid(elements->barClock.font, "0 : 00 : 00", elements->barClock.color)), 0, &elements->barClock.rect);
	SDL_RenderCopy(renderer, elements->bpm_control.BPMtexture, 0, &elements->bpm_control.rect);
	for (Uint8 i = 0; i < 16; i++)
	{
		SDL_RenderCopy(renderer, elements->pad[i].pad, 0, &elements->pad[i].rect);
	}
}
SDL_Rect CreateRect(int h, int w, int x, int y)
{
	SDL_Rect rect;
	rect.h = h;
	rect.w = w;
	rect.x = x;
	rect.y = y;
	return rect;
}
SDL_Color CreateColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
	SDL_Color colour;
	colour.a = alpha;
	colour.r = red;
	colour.g = green;
	colour.b = blue;
	return colour;
}
void NewTextureOnRender(SDL_Renderer* rend, SDL_Texture* src, SDL_Texture* dst, SDL_Rect rect)
{
	//SDL_RenderCopy(rend, updatePadButton(src, rend, dst), 0, &rect);
	updatePadButton(src, rend, dst);
}
void updateTimeTTF(SDL_Renderer* renderer, GUI_elements* elements, TimeLapse* lapse)
{
	/*SDL_Surface* surface;
	SDL_DestroyTexture(elements->barClock.bar_clock);*/
	char* TIME = (char*)calloc(12, sizeof(char));
	updateTime(lapse, TIME, elements->bpm_control.bpm_value);
	/*surface = TTF_RenderText_Solid(elements->barClock.font, TIME, elements->barClock.color);
	elements->barClock.bar_clock = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_RenderCopy(renderer, elements->barClock.bar_clock, 0, &elements->barClock.rect);
	SDL_FreeSurface(surface);*/
	printf("TIME: %s\n", TIME);
	free(TIME);
}
void changeBPMTTF(SDL_Renderer* renderer, GUI_elements* elements)
{
	SDL_DestroyTexture(elements->bpm_control.BPMtexture);
	char* currentBPM = (char*)calloc(4, sizeof(char));
	sprintf_s(currentBPM, 4, "%03d", elements->bpm_control.bpm_value);
	SDL_Surface* surface = TTF_RenderText_Solid(elements->barClock.font, currentBPM, elements->barClock.color);
	elements->bpm_control.BPMtexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_RenderCopy(renderer, elements->bpm_control.BPMtexture, 0, &elements->bpm_control.rect);
	SDL_FreeSurface(surface);
	free(currentBPM);
}
void UpdateScreen(SDL_Renderer* renderer, GUI_elements* elements)
{
	SDL_RenderCopy(renderer, elements->backBround.frame, 0, 0);
	SDL_RenderCopy(renderer, elements->padsFrame.frame, 0, &elements->padsFrame.rect);
	SDL_RenderCopy(renderer, elements->functionalFrame.frame, 0, &elements->functionalFrame.rect);
	SDL_RenderCopy(renderer, elements->bpm_control.BPMtexture, 0, &elements->bpm_control.rect);
	SDL_RenderCopy(renderer, elements->barClock.bar_clock, 0, &elements->barClock.rect);
	SDL_RenderCopy(renderer, elements->StopButton.frame, 0, &elements->StopButton.rect);
	SDL_RenderCopy(renderer, elements->PlayButton.frame, 0, &elements->PlayButton.rect);
	SDL_RenderCopy(renderer, elements->ToStartButton.frame, 0, &elements->ToStartButton.rect);
	SDL_RenderCopy(renderer, elements->RecordButton.frame, 0, &elements->RecordButton.rect);
	SDL_RenderCopy(renderer, elements->ClearButton.frame, 0, &elements->ClearButton.rect);
	SDL_RenderCopy(renderer, elements->QuantizeButton.frame, 0, &elements->QuantizeButton.rect);
	for (Uint8 i = 0; i < 16; i++)
	{
		SDL_RenderCopy(renderer, elements->pad[i].pad, 0, &elements->pad[i].rect);
	}
}
