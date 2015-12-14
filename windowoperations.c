#include "windowoperations.h"

bool DMinitialize(SDL_Window** window, GUI_elements* elements, SDL_Renderer** renderer, FramesChange* frames)
{
	bool success = true;
	SDL_Texture* texture = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Failed to load Drum Machine: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		*window = SDL_CreateWindow("Drum Machine", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (*window == NULL)
		{
			printf("Failed to load Drum Machine: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			/*---Scene Behind Texture---*/
			texture = loadTexture("Frames\\Texture.png", *renderer);			
			SDL_RenderClear(*renderer);
			SDL_RenderCopy(*renderer, texture, 0, 0);
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
	frames->pad = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Pad.bmp"));
	frames->padPressed = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\PadPressed.bmp"));
	frames->Clear = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Clear.bmp"));
	frames->ClearPressed = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\ClearPressed.bmp"));
	frames->Record = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Record.bmp"));
	frames->RecordPressed = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\RecordPressed.bmp"));
	frames->Play = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Play.bmp"));
	frames->PlayPressed = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\PlayPressed.bmp"));
	frames->Pause = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Pause.bmp"));
	frames->PausePressed = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\PausePressed.bmp"));
	frames->Stop = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Stop.bmp"));
	frames->StopPressed = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\StopPressed.bmp"));
	frames->ToStart = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\ToStart.bmp"));
	frames->ToStartPressed = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\ToStartPressed.bmp"));
	frames->Quantize = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Quantize.bmp"));
	frames->QuantizePressed = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\QuantizePressed.bmp"));
	
	elements->padsFrame = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\PadsFrame.bmp"));
	elements->functionalFrame = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\FunctionalFrame.bmp"));
	elements->RecordButton.frame = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Record.bmp"));
	elements->PlayButton.frame = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Play.bmp"));
	elements->PauseButton.frame = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Pause.bmp"));
	elements->StopButton.frame = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Stop.bmp"));
	elements->ToStartButton.frame = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\ToStart.bmp"));
	elements->ClearButton.frame = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Clear.bmp"));
	elements->QuantizeButton.frame = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Quantize.bmp"));
	elements->pad_1.pad = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Pad.bmp"));
	elements->pad_2.pad = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Pad.bmp"));
	elements->pad_3.pad = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Pad.bmp"));
	elements->pad_4.pad = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Pad.bmp"));
	elements->pad_5.pad = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Pad.bmp"));
	elements->pad_6.pad = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Pad.bmp"));
	elements->pad_7.pad = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Pad.bmp"));
	elements->pad_8.pad = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Pad.bmp"));
	elements->pad_9.pad = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Pad.bmp"));
	elements->pad_10.pad = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Pad.bmp"));
	elements->pad_11.pad = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Pad.bmp"));
	elements->pad_12.pad = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Pad.bmp"));
	elements->pad_13.pad = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Pad.bmp"));
	elements->pad_14.pad = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Pad.bmp"));
	elements->pad_15.pad = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Pad.bmp"));
	elements->pad_16.pad = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Frames\\Pad.bmp"));
	if (elements->padsFrame == NULL)
	{
		printf("Texture error: %s\n", SDL_GetError());
		success = false;
	}

	return success;
}
void DMclose(SDL_Window** window, GUI_elements** elements)
{
	SDL_DestroyWindow(*window);
	SDL_Quit();
}
SDL_Texture* updatePadButton(SDL_Texture* texture, SDL_Renderer* renderer, SDL_Texture* frame)
{
	SDL_DestroyTexture(texture);
	texture = frame;
	if (texture == NULL) printf("Frame error: %s", SDL_GetError());
	return texture;
}
SDL_Texture* loadTexture(char* const path, SDL_Renderer* renderer)
{
	SDL_Texture* texture = NULL;
	SDL_Surface* textureSurface = IMG_Load(path);
	int imgFlags = IMG_INIT_PNG;

	SDL_SetRenderDrawColor(renderer, 0x0f, 0x1f, 0xef, 0xff);

	if (!(IMG_Init(imgFlags) & imgFlags))
		printf("1)Texture error: %s\n", SDL_GetError());
	if (textureSurface == NULL)
		printf("2)Texture error: %s\n", SDL_GetError());
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer, textureSurface);
		if (texture == NULL)
			printf("3)Texture error: %s\n", SDL_GetError());	
		SDL_FreeSurface(textureSurface);
	}
	return texture;
}
void BlitGUI(GUI_elements* elements, SDL_Renderer* renderer)
{
	Uint8 padsSpace = 20;
	Uint8 ButtonWidth = 38;
	Uint8 ButtonSpace = 10;
	SDL_Rect functionalDstRect = CreateRect(SCREEN_HEIGHT / 10, 2 * SCREEN_WIDTH / 3, SCREEN_WIDTH / 3, 0);
	SDL_Rect playListDstRect = CreateRect(SCREEN_HEIGHT / 10, 2 * SCREEN_WIDTH / 3,
		SCREEN_WIDTH / 3, SCREEN_HEIGHT - SCREEN_HEIGHT / 10);
	SDL_Rect padsFrameDstRect = CreateRect(SCREEN_HEIGHT - playListDstRect.h - functionalDstRect.h,
		2 * SCREEN_WIDTH / 3, SCREEN_WIDTH / 3, SCREEN_HEIGHT / 10);
	/*---OMG GRAPHICS STARTS FROM HERE---*/
	/*---First line Pads---*/
	elements->pad_1.rect = CreateRect((padsFrameDstRect.h - padsSpace*5) / 4,
		(padsFrameDstRect.w - padsSpace*5) / 4, padsFrameDstRect.x + padsSpace, padsFrameDstRect.y + padsSpace);
	elements->pad_2.rect = CreateRect((padsFrameDstRect.h - padsSpace * 5) / 4,	(padsFrameDstRect.w - padsSpace * 5) / 4,
		padsFrameDstRect.x + 2 * padsSpace + 1 * elements->pad_1.rect.w, padsFrameDstRect.y + padsSpace);
	elements->pad_3.rect = CreateRect((padsFrameDstRect.h - padsSpace * 5) / 4, (padsFrameDstRect.w - padsSpace * 5) / 4,
		padsFrameDstRect.x + 3 * padsSpace + 2 * elements->pad_1.rect.w, padsFrameDstRect.y + padsSpace);
	elements->pad_4.rect = CreateRect((padsFrameDstRect.h - padsSpace * 5) / 4, (padsFrameDstRect.w - padsSpace * 5) / 4,
		padsFrameDstRect.x + 4 * padsSpace + 3 * elements->pad_1.rect.w, padsFrameDstRect.y + padsSpace);
	/*---Second line Pads---*/
	elements->pad_5.rect = CreateRect((padsFrameDstRect.h - padsSpace * 5) / 4,
		(padsFrameDstRect.w - padsSpace * 5) / 4, padsFrameDstRect.x + padsSpace,
		padsFrameDstRect.y + 2 * padsSpace + elements->pad_1.rect.h);
	elements->pad_6.rect = CreateRect((padsFrameDstRect.h - padsSpace * 5) / 4, (padsFrameDstRect.w - padsSpace * 5) / 4,
		padsFrameDstRect.x + 2 * padsSpace + 1 * elements->pad_1.rect.w,
		padsFrameDstRect.y + 2 * padsSpace + elements->pad_1.rect.h);
	elements->pad_7.rect = CreateRect((padsFrameDstRect.h - padsSpace * 5) / 4, (padsFrameDstRect.w - padsSpace * 5) / 4,
		padsFrameDstRect.x + 3 * padsSpace + 2 * elements->pad_1.rect.w,
		padsFrameDstRect.y + 2 * padsSpace + elements->pad_1.rect.h);
	elements->pad_8.rect = CreateRect((padsFrameDstRect.h - padsSpace * 5) / 4, (padsFrameDstRect.w - padsSpace * 5) / 4,
		padsFrameDstRect.x + 4 * padsSpace + 3 * elements->pad_1.rect.w,
		padsFrameDstRect.y + 2 * padsSpace + elements->pad_1.rect.h);
	/*---Third line Pads---*/
	elements->pad_9.rect = CreateRect((padsFrameDstRect.h - padsSpace * 5) / 4,
		(padsFrameDstRect.w - padsSpace * 5) / 4, padsFrameDstRect.x + padsSpace,
		padsFrameDstRect.y + 3 * padsSpace + 2 * elements->pad_1.rect.h);
	elements->pad_10.rect = CreateRect((padsFrameDstRect.h - padsSpace * 5) / 4, (padsFrameDstRect.w - padsSpace * 5) / 4,
		padsFrameDstRect.x + 2 * padsSpace + 1 * elements->pad_1.rect.w,
		padsFrameDstRect.y + 3 * padsSpace + 2 * elements->pad_1.rect.h);
	elements->pad_11.rect = CreateRect((padsFrameDstRect.h - padsSpace * 5) / 4, (padsFrameDstRect.w - padsSpace * 5) / 4,
		padsFrameDstRect.x + 3 * padsSpace + 2 * elements->pad_1.rect.w,
		padsFrameDstRect.y + 3 * padsSpace + 2 * elements->pad_1.rect.h);
	elements->pad_12.rect = CreateRect((padsFrameDstRect.h - padsSpace * 5) / 4, (padsFrameDstRect.w - padsSpace * 5) / 4,
		padsFrameDstRect.x + 4 * padsSpace + 3 * elements->pad_1.rect.w,
		padsFrameDstRect.y + 3 * padsSpace + 2 * elements->pad_1.rect.h);
	/*---Forth line Pads---*/
	elements->pad_13.rect = CreateRect((padsFrameDstRect.h - padsSpace * 5) / 4,
		(padsFrameDstRect.w - padsSpace * 5) / 4, padsFrameDstRect.x + padsSpace,
		padsFrameDstRect.y + 4 * padsSpace + 3 * elements->pad_1.rect.h);
	elements->pad_14.rect = CreateRect((padsFrameDstRect.h - padsSpace * 5) / 4, (padsFrameDstRect.w - padsSpace * 5) / 4,
		padsFrameDstRect.x + 2 * padsSpace + 1 * elements->pad_1.rect.w,
		padsFrameDstRect.y + 4 * padsSpace + 3 * elements->pad_1.rect.h);
	elements->pad_15.rect = CreateRect((padsFrameDstRect.h - padsSpace * 5) / 4, (padsFrameDstRect.w - padsSpace * 5) / 4,
		padsFrameDstRect.x + 3 * padsSpace + 2 * elements->pad_1.rect.w,
		padsFrameDstRect.y + 4 * padsSpace + 3 * elements->pad_1.rect.h);
	elements->pad_16.rect = CreateRect((padsFrameDstRect.h - padsSpace * 5) / 4, (padsFrameDstRect.w - padsSpace * 5) / 4,
		padsFrameDstRect.x + 4 * padsSpace + 3 * elements->pad_1.rect.w,
		padsFrameDstRect.y + 4 * padsSpace + 3 * elements->pad_1.rect.h);
	/*---Buttons---*/
	elements->StopButton.rect = CreateRect(functionalDstRect.h / 3, ButtonWidth,
		functionalDstRect.x + ButtonSpace, functionalDstRect.h / 3);
	elements->PlayButton.rect = CreateRect(functionalDstRect.h / 3, ButtonWidth,
		elements->StopButton.rect.x + ButtonWidth + ButtonSpace, functionalDstRect.h / 3);
	elements->ToStartButton.rect = CreateRect(functionalDstRect.h / 3, ButtonWidth,
		elements->PlayButton.rect.x + ButtonWidth + ButtonSpace, functionalDstRect.h / 3);
	elements->RecordButton.rect = CreateRect(functionalDstRect.h / 3, ButtonWidth,
		elements->ToStartButton.rect.x + ButtonWidth + ButtonSpace, functionalDstRect.h / 3);
	elements->ClearButton.rect = CreateRect(functionalDstRect.h / 3, ButtonWidth,
		elements->RecordButton.rect.x + ButtonWidth + ButtonSpace, functionalDstRect.h / 3);
	elements->QuantizeButton.rect = CreateRect(functionalDstRect.h / 3, ButtonWidth,
		SCREEN_WIDTH - ButtonWidth - ButtonWidth, functionalDstRect.h / 3);
	
	SDL_RenderCopy(renderer, elements->functionalFrame, 0, &functionalDstRect);
	SDL_RenderCopy(renderer, elements->padsFrame, 0, &padsFrameDstRect);
	SDL_RenderCopy(renderer, elements->StopButton.frame, 0, &elements->StopButton.rect);
	SDL_RenderCopy(renderer, elements->PlayButton.frame, 0, &elements->PlayButton.rect);
	SDL_RenderCopy(renderer, elements->ToStartButton.frame, 0, &elements->ToStartButton.rect);
	SDL_RenderCopy(renderer, elements->RecordButton.frame, 0, &elements->RecordButton.rect);
	SDL_RenderCopy(renderer, elements->ClearButton.frame, 0, &elements->ClearButton.rect);
	SDL_RenderCopy(renderer, elements->QuantizeButton.frame, 0, &elements->QuantizeButton.rect);
	SDL_RenderCopy(renderer, elements->pad_1.pad, 0, &elements->pad_1.rect);
	SDL_RenderCopy(renderer, elements->pad_2.pad, 0, &elements->pad_2.rect);
	SDL_RenderCopy(renderer, elements->pad_3.pad, 0, &elements->pad_3.rect);
	SDL_RenderCopy(renderer, elements->pad_4.pad, 0, &elements->pad_4.rect);
	SDL_RenderCopy(renderer, elements->pad_5.pad, 0, &elements->pad_5.rect);
	SDL_RenderCopy(renderer, elements->pad_6.pad, 0, &elements->pad_6.rect);
	SDL_RenderCopy(renderer, elements->pad_7.pad, 0, &elements->pad_7.rect);
	SDL_RenderCopy(renderer, elements->pad_8.pad, 0, &elements->pad_8.rect);
	SDL_RenderCopy(renderer, elements->pad_9.pad, 0, &elements->pad_9.rect);
	SDL_RenderCopy(renderer, elements->pad_10.pad, 0, &elements->pad_10.rect);
	SDL_RenderCopy(renderer, elements->pad_11.pad, 0, &elements->pad_11.rect);
	SDL_RenderCopy(renderer, elements->pad_12.pad, 0, &elements->pad_12.rect);
	SDL_RenderCopy(renderer, elements->pad_13.pad, 0, &elements->pad_13.rect);
	SDL_RenderCopy(renderer, elements->pad_14.pad, 0, &elements->pad_14.rect);
	SDL_RenderCopy(renderer, elements->pad_15.pad, 0, &elements->pad_15.rect);
	SDL_RenderCopy(renderer, elements->pad_16.pad, 0, &elements->pad_16.rect);
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
void NewTextureOnRender(SDL_Renderer* rend, SDL_Texture* src, SDL_Texture* dst, SDL_Rect rect)
{
	SDL_RenderCopy(rend, updatePadButton(src, rend, dst), 0, &rect);
}