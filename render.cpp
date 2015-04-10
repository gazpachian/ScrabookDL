#include "render.hpp"

Renderer::Renderer(const char * window_title, Vector2 dims, Vector3 bg_col) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize at __LINE__, error: %s\n",
                SDL_GetError());
    }
    window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, dims.getX(), dims.getY(), SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fprintf(stderr, "SDL could not initialize at __LINE__, error: %s\n",
                SDL_GetError());
    }
    background_color = new Vector3(bg_col.getR(), bg_col.getG(), bg_col.getB());
}

Renderer::~Renderer() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int Renderer::addBitmap(const char * filename, shared_ptr<Vector2> initialPosition) {
    SDL_Surface * win_surface = SDL_GetWindowSurface(window);
    SDL_Surface * import = SDL_LoadBMP(filename);
    SDL_Surface * screen_adapter = NULL;
    if(import == NULL) {
        fprintf(stderr, "Unable to load image at __LINE__, SDL error: %s\n"
                , SDL_GetError());
        return -1;
    }

    screen_adapter = SDL_ConvertSurface(import, win_surface->format, 0);
    if(screen_adapter == NULL) {
        fprintf(stderr, "Unable to optimize image at __LINE__, SDL error: %s\n"
                , SDL_GetError());
        return -1;
    }
    SDL_FreeSurface(import);
    shared_ptr<Sprite> r (new Sprite());
    r->setSprite(screen_adapter);
    r->setPosition(initialPosition);
    sprites.push_back(r);
    return sprites.size() - 1;
}

void Renderer::renderAll() {
    SDL_Surface * win_surface = SDL_GetWindowSurface(window);
    SDL_FillRect(win_surface, NULL, SDL_MapRGB(win_surface->format, 
                background_color->getR(), background_color->getG(), background_color->getB()));
    for(int i = 0; i < sprites.size(); ++i) {
        blitSprite(*sprites[i]);
    }
    SDL_UpdateWindowSurface(window);
    SDL_Delay(5);
}

void Renderer::updatePosition(int sprite_ID, shared_ptr<Vector2> pos) {
    sprites[sprite_ID]->setPosition(pos);
}

void Renderer::blitSprite(Sprite r ) { 
    if(r.getSprite() == NULL) {
        fprintf(stderr, "Sprite not initialized \n");
        return;
    }
    SDL_Surface * win_surface = SDL_GetWindowSurface(window);
    SDL_Rect rect;
    rect.x = r.getPosition()->getX();
    rect.y = r.getPosition()->getY();
    SDL_BlitSurface(r.getSprite(), NULL, win_surface, &rect);
}

Sprite::Sprite() {
    shared_ptr<Vector2> pos (new Vector2(0, 0));
    position = pos;
}
Sprite::~Sprite() {
}
void Sprite::setPosition(shared_ptr<Vector2> pos) {
    position = pos;
}
void Sprite::setSprite(SDL_Surface * screen_sprite) {
    sprite = screen_sprite;
}

SDL_Surface * Sprite::getSprite() {
    return sprite;
}

shared_ptr<Vector2> Sprite::getPosition() {
    return position;
}
