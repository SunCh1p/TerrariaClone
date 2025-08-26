/*This source code copyrighted by Lazy Foo' Productions 2004-2025
and may not be redistributed without written permission.*/

/* Headers */
//Using SDL and STL string
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>
#include <vector>
#include <iostream>

int main(int argc, char* argv[]){
    // Initialize SDL3
    SDL_Init(SDL_INIT_VIDEO);
    // Initialize SDL3_ttf
    TTF_Init();

    // Create SDL Window
    SDL_Window* window = SDL_CreateWindow("SDL3 Test", 420, 300, SDL_WINDOW_RESIZABLE);
    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Create the Renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    if(!renderer){
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        return -1;
    }

    // Load Font with SDL3_ttf
    TTF_Font* font = TTF_OpenFont("../fonts/Roboto/Roboto-VariableFont_wdth,sght.ttf",16);
    if(!font){
        std::cout << "Failed to laod font: " << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        return -1;
    }

    // Text to render
    std::string text = "Hello World!";

    // Vector of surfaces
    std::vector<SDL_Surface*> surfaces;
    surfaces.reserve(text.size());

    // Render each character as a surface
    for (size_t i = 0; i < text.size(); i++) {
        SDL_Surface* textSurface = TTF_RenderGlyph_LCD(font, text[i], SDL_Color{255, 255, 255, 255}, SDL_Color{0, 0, 0, 255});
        if (!textSurface) {
            std::cerr << "Failed to create text surface: " << SDL_GetError() << std::endl;
            continue; // Skip if surface creation fails
        }
        surfaces.push_back(textSurface);
    }

    // Calculate total width and max height for the combined surface
    int totalWidth = 0;
    int maxHeight = 0;
    for (auto& surf : surfaces) {
        totalWidth += surf->w + 5; // Add spacing between glyphs
        if (surf->h > maxHeight) {
            maxHeight = surf->h;
        }
    }
    SDL_FRect rect{5, 50, static_cast<float>(totalWidth), static_cast<float>(maxHeight)};

    // Create the final combined surface
    SDL_Surface* combinedSurface = SDL_CreateSurface(totalWidth, maxHeight, SDL_PIXELFORMAT_RGBA32);
    if (!combinedSurface) {
        std::cerr << "Failed to create combined surface: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Blit each glyph onto the combined surface
    int xOffset = 0;
    for (auto& surf : surfaces) {
        SDL_Rect destRect = {xOffset, 0, surf->w, surf->h};
        SDL_BlitSurface(surf, NULL, combinedSurface, &destRect);
        xOffset += surf->w + 5; // Move to the next position with spacing
        SDL_DestroySurface(surf); // Free individual surfaces after blitting
    }

    surfaces.clear(); // Clear the vector since we don't need it anymore

    // Convert the combined surface to a texture
    SDL_Texture* combinedTexture = SDL_CreateTextureFromSurface(renderer, combinedSurface);
    SDL_DestroySurface(combinedSurface); // Free the surface after conversion

    // Event loop
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT || 
                (event.type == SDL_EVENT_KEY_DOWN && event.key.scancode == SDL_SCANCODE_ESCAPE)) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Render the combined text texture
        SDL_RenderTexture(renderer, combinedTexture, NULL, &rect);

        SDL_RenderPresent(renderer);
    }

    // Cleanup
    SDL_DestroyTexture(combinedTexture);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Shutdown SDL3 and TTF
    TTF_Quit();
    SDL_Quit();

    return 0;

}