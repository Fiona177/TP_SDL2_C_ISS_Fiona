#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL2/SDL.h"
#define WINDOW_W 100
#define WINDOW_H 100
#define PRECISION 0.001

typedef struct sdl_manager
{
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
    SDL_Texture *pTexture;
    SDL_Surface *pSurface;
}sdl_manager;

int main(int argc, char *argv[])
{

  //Initialisation des differentes variable
  sdl_manager SDL_Man;
  int accueil;

    //La fonction SDL_Init renvoie 0 si l'initialisation a rÃ©ussi et -1 en cas d'erreur.
    //La SDL se divise en plusieurs sous-systÃ¨mes. Pour initialiser un ou plusieurs sous-systÃ¨mes, on utilisera la syntaxe suivante :

    //SDL_Init(SOUS_SYSTEME);//Pour un seul sous-systÃ¨me
    //SDL_Init(SOUS_SYSTEME_1 | SOUS_SYSTEME2 | SOUS_SYSTEME_3 | ... );//Pour plusieurs sous-systÃ¨mes

    if(SDL_Init(SDL_INIT_VIDEO) < 0) //Initialise tous les sous-systemes.
  {
     printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());//on affiche l'erreur
     return EXIT_FAILURE;//on sort du programme pour Ã©viter de plus gros problÃ¨mes
  }

  //CrÃ©ation d'une fenÃªtre
  SDL_Man.pWindow = SDL_CreateWindow("Premiere fenetre SDL", 0, 0, 400, 400, SDL_WINDOW_RESIZABLE);

  if (SDL_Man.pWindow == NULL)  //gestion des erreurs
  {
      printf("Erreur lors de la creation d'une fenetre : %s", SDL_GetError());
      return EXIT_FAILURE;
  }

  //Creation d'un rendu
  SDL_Man.pRenderer = SDL_CreateRenderer(SDL_Man.pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (SDL_Man.pRenderer == NULL)  //gestion des erreurs
  {
      printf("Erreur lors de la creation d'un rendu : %s", SDL_GetError());
      return EXIT_FAILURE;
  }

    printf("\t\t=== Accueil ===\n");
    printf("\t\t===============\n\n");
    printf("\t1. fenetre rouge\n");
    printf("\t2. Rectangle vide\n");
    printf("\t3. Rectangle plein\n");
    printf("\t4. Cercle vide\n");
    printf("\t5. Cercle plein\n");
    printf("\t6. Import d'une SDL_Man.pSurface\n");
    printf("\t7. Quitter\n\n");
    scanf("%d", &accueil);
    printf("\n");

  switch (accueil)
  {
    case 1: // Permet d'afficher une fenetre rouge
       printf("Voici une SDL_Man.pWindow rouge\n\n");
       //Permet de rendre la fenÃªtre rouge
    SDL_SetRenderDrawColor(SDL_Man.pRenderer, 255, 0, 0, 255);
    SDL_RenderClear(SDL_Man.pRenderer);
    SDL_RenderPresent(SDL_Man.pRenderer);
    SDL_Delay(3000);//Permet de mettre un temps de 3 secondes pour voir la fenetre
    SDL_DestroyRenderer(SDL_Man.pRenderer); //Libere l'espace aloue au rendu
    SDL_DestroyWindow(SDL_Man.pWindow); //Libere l'espace aloue Ã  la fenetre
    SDL_Quit(); //Permet de quitter la SDL
       break;
    case 2: // Permet d'afficher Rectangle vide
       printf("Voici un Rectangle vide\n\n");
     SDL_Rect rectvide = {10,10,50,50};//Ceci est un rectangle  de dimensions 50*50 et de position (10;10)
      SDL_SetRenderDrawColor(SDL_Man.pRenderer, 0, 0, 255, 0);
      SDL_RenderDrawRect(SDL_Man.pRenderer, &rectvide);
      SDL_RenderPresent(SDL_Man.pRenderer);
      SDL_Delay(3000);//Permet de mettre un temps de 3 secondes pour voir la fenetre
    SDL_DestroyRenderer(SDL_Man.pRenderer); //Libere l'espace aloue au rendu
    SDL_DestroyWindow(SDL_Man.pWindow); //Libere l'espace aloue Ã  la fenetre
    SDL_Quit(); //Permet de quitter la SDL
       break;
    case 3: // Permet d'afficher Rectangle plein
       printf("Voici un Rectangle plein\n\n");
     SDL_Rect rectplein = {10,10,50,50};//Ceci est un rectangle  de dimensions 50*50 et de position (10;10)
      SDL_SetRenderDrawColor(SDL_Man.pRenderer, 0, 0, 255, 0);
      SDL_RenderFillRect(SDL_Man.pRenderer, &rectplein);
      SDL_RenderPresent(SDL_Man.pRenderer);
      SDL_Delay(3000);//Permet de mettre un temps de 3 secondes pour voir la fenetre
    SDL_DestroyRenderer(SDL_Man.pRenderer); //Libere l'espace aloue au rendu
    SDL_DestroyWindow(SDL_Man.pWindow); //Libere l'espace aloue Ã  la fenetre
    SDL_Quit(); //Permet de quitter la SDL
       break;
    case 4: // Permet d'afficher Cercle vide
       printf("Voici un Cercle vide\n\n");
     SDL_SetRenderDrawColor(SDL_Man.pRenderer, 0, 0, 255, 0);
      for(double i = 0.0; i < 360; i+= PRECISION)
          SDL_RenderDrawPoint(SDL_Man.pRenderer,WINDOW_W /2 - cos(i)*WINDOW_W / 2 +10,WINDOW_H / 2 - sin(i)* WINDOW_H / 2 +10);
      SDL_RenderPresent(SDL_Man.pRenderer);
      SDL_Delay(3000);//Permet de mettre un temps de 3 secondes pour voir la fenetre
    SDL_DestroyRenderer(SDL_Man.pRenderer); //Libere l'espace aloue au rendu
    SDL_DestroyWindow(SDL_Man.pWindow); //Libere l'espace aloue Ã  la fenetre
    SDL_Quit(); //Permet de quitter la SDL
       break;
    case 5: // Permet d'afficher Cercle plein
       printf("Voici un Cercle plein\n\n");
     SDL_SetRenderDrawColor(SDL_Man.pRenderer, 0, 0, 255, 0);
      for(double i = 0.0; i < 360; i+= PRECISION)
          SDL_RenderDrawLine(SDL_Man.pRenderer,WINDOW_W /2 - cos(i)*WINDOW_W / 2 +30,WINDOW_H / 2 - sin(i)* WINDOW_H / 2 +30,cos(i)*WINDOW_W /2 ,sin(i)*WINDOW_W /2 );
      SDL_RenderPresent(SDL_Man.pRenderer);
      SDL_Delay(3000);//Permet de mettre un temps de 3 secondes pour voir la fenetre
    SDL_DestroyRenderer(SDL_Man.pRenderer); //Libere l'espace aloue au rendu
    SDL_DestroyWindow(SDL_Man.pWindow); //Libere l'espace aloue Ã  la fenetre
    SDL_Quit(); //Permet de quitter la SDL
       break;
    case 6: // Permet d'afficher Import d'une Surface
       printf("Voici un Import d'une SDL_Man.pSurface\n\n");
     SDL_Man.pSurface = SDL_LoadBMP("image.bmp");
    if(!SDL_Man.pSurface)
    {
        printf("Erreur de chargement de l'SDL_Man.pSurface : %s",SDL_GetError());
        return -1;
    }
    SDL_Man.pTexture = SDL_CreateTextureFromSurface(SDL_Man.pRenderer,SDL_Man.pSurface);  //La texture SDL_Man.pTexture contient maintenant le SDL_Man.pSurface importée
    //SDL_FreeSurface(SDL_Man.pSurface); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface

    SDL_Rect position;
    position.x = 100;
    position.y = 200;
    SDL_QueryTexture(SDL_Man.pTexture, NULL, NULL, &position.w, &position.h);
    SDL_RenderCopy(SDL_Man.pRenderer, SDL_Man.pTexture, NULL, &position);
    SDL_RenderPresent(SDL_Man.pRenderer);

    SDL_DestroyTexture(SDL_Man.pTexture);
    SDL_FreeSurface(SDL_Man.pSurface);

    SDL_Delay(3000);//Permet de mettre un temps de 3 secondes pour voir la fenetre
    SDL_DestroyRenderer(SDL_Man.pRenderer); //Libere l'espace aloue au rendu
    SDL_DestroyWindow(SDL_Man.pWindow); //Libere l'espace aloue Ã  la fenetre
    SDL_Quit(); //Permet de quitter la SDL
       break;

    case 7: // affiche au revoir si le joueur quitte le jeu
        exit(0);
       break;
  }
    return 0;
}
