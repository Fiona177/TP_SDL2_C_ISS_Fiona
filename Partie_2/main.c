#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

int main(int argc, char *argv[])
{

    SDL_Window* fenetre;
	SDL_Renderer* render;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) //Initialise tous les sous-systemes.
	{
	   printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());//on affiche l'erreur
	   return EXIT_FAILURE;//on sort du programme pour éviter de plus gros problèmes
	}
	//Création d'une fenêtre
	fenetre = SDL_CreateWindow("Premiere fenetre SDL", 0, 0, 400, 400, SDL_WINDOW_RESIZABLE);

	if (fenetre == NULL)  //gestion des erreurs
	{
	    printf("Erreur lors de la creation d'une fenetre : %s", SDL_GetError());
	    return EXIT_FAILURE;
	}
	//Creation d'un renderer
	render = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (render == NULL)  //gestion des erreurs
	{
	    printf("Erreur lors de la creation d'une fenetre : %s", SDL_GetError());
	    return EXIT_FAILURE;
	}

	//Image au format png
	/*SDL_SetRenderDrawColor(render,255,0,0,255);
	SDL_RenderClear(render);
	SDL_Surface *image = IMG_Load("blop.png"); //Importer une image
	SDL_Texture *texture = SDL_CreateTextureFromSurface(render,image); //La texture contient maintenant l'image importée

	SDL_Rect position;
	position.x = 100;
	position.y = 200;

	SDL_RenderCopy(render;texture,NULL,&position);
	SDL_RenderPresent(render);
	SDL_Delay(3000);

	SDL_DestroyRenderer(render); //Libere l'espace aloue au render
	SDL_DestroyWindow(fenetre); //Libere l'espace aloue Ã  la fenetre
	SDL_Quit(); //Permet de quitter la SDL


    return 0;*/

	//Tileset
	int quitter;

    SDL_Surface *image = IMG_Load("helicopter.png"); //Importer une image
	SDL_Texture *texture = SDL_CreateTextureFromSurface(render,image); //La texture contient maintenant l'image importée

	SDL_Rect rect = {0,0,128,55};
	SDL_Rect rect2;
	rect2.w = 128;
	rect2.h = 55;

	while(quitter!=1)
	{
		rect.x = rect.x + 128;
		if (rect.x>512)
		{
			rect.x=0;
		}
		SDL_RenderCopy(render,texture,&rect,&rect2);
		SDL_RenderPresent(render);
		SDL_Delay(1);
		SDL_DestroyRenderer(render);
		scanf("%d", &quitter);
	}

    SDL_DestroyRenderer(render); //Libere l'espace aloue au render
	SDL_DestroyWindow(fenetre); //Libere l'espace aloue Ã  la fenetre
	SDL_Quit(); //Permet de quitter la SDL


    return 0;
}
