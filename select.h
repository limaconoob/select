/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 01:39:01 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/29 04:15:16 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

# define PROCESS    42
# define TRUE       0
# define FALSE      1

# define MAPP       coucou->mapper
# define MATR       coucou->matrix
# define WIND       coucou->wind
# define MOUS       coucou->mous
# define CURS       coucou->curs
# define SLID       coucou->slide
# define TERM       coucou->term
# define TTRI       coucou->tab_tri
# define SMAX       coucou->size_max
# define MSIZ       coucou->mat_size
# define NCOL       coucou->nb_col
# define NFIL       coucou->nb_files
# define FIND       coucou->finder
# define FINE       coucou->fine
# define TMP        coucou->tmp

# define SIZE       (NCOL * (SMAX + 3)) + 1
# define MCOR       MAPP[coord[1]][coord[0]]->coord
# define MAPQ       MAPP[p][q]->coord
# define MAPO       MAPP[p][q]

# define CPY        ft_strcpy
# define NCPY       ft_strncpy
# define MCPY       ft_memcpy
# define NCMP       ft_strncmp
# define LEN        ft_strlen
# define BZE        ft_bzero

# define INT        sizeof(int)

///1
///De
///Fr Définition des types
typedef unsigned char     u8;       //
typedef unsigned short    u16;      //
typedef unsigned long     u32;      //
typedef signed char       s8;       //
typedef signed short      s16;      //
typedef signed long       s32;      //
///1

///2
///De Mousetaste
///Fr Énumération des boutons de souris
typedef enum e_mouse
{ LCK,                              //Bouton Gauche
  MCK,                              //Bouton Molette
  RCK,                              //Bouton Droit
  WUP = 64,                         //Molette vers le Haut
  WDN,                              //Molette vers le Bas
  DDL = 32,                         //DnD Gauche
  DDM,                              //DnD Molette
  DDR,                              //DnD Droite
} t_mouse;
///2

///3
///De
///Fr Énumération et définitions des touches du clavier
typedef enum e_keys
{ SUPPR = 126,                      //Touche Supprimer
  DEL = 127,                        //Touche Retour-Arrière
  LIN = 68,                         //Touche flèche de Gauche
  REC = 67,                         //Touche flèche de Droite
  UNT = 66,                         //Touche flèche du Bas
  TOP = 65,                         //Touche flèche du Haut
  ESC = 27,                         //Touche Échap
  SPC = 32,                         //Touche Espace
  ATF = -58,                        //Alt + 'f'
  TAB = 9                           //Touche Tabulation
} t_keys;
///3

///3
///De
///Fr Énumération des erreurs du programme
typedef enum e_error
{ Malloc = 0x00,                    //Mémoire dynamique insuffisante
  Argument = 0x01,                  //Mauvais argument
  MissingFile = 0x02,               //Fichier absent
  Access = 0x04,                    //Fichier interdit d'accès
  TermInit = 0x08,                  //Contrôle du terminal compromis
  MissingArgument = 0x10 } t_error; //Arguments absents
///3

/*
///3
///De
///Fr Énumération des avertissements du programme
typedef enum e_warning
{  } t_warning;                     //
///3

///3
///De
///Fr Énumération des réparations du programme
typedef enum e_cure
{  } t_cure;                        //
///3
*/

///3
///De
///Fr Structure contenue dans la matrice du terminal
typedef struct s_tab
{ char c;                           //Caractère à afficher
  char attr[10][8]; } t_tab;        //Attributs du caractère
///3

///3
///De
///Fr Liste des fichiers sélectionnables (ft_select)
typedef struct s_map
{ char *name;                       //Nom du fichier
  char attr[10][8];                 //Attributs du mot
  int index;                        //Position dans le tableau de tri
  int coord[2]; } t_map;            //Position dans la matrice
///3

///3
///De
///Fr Structure de définition du terminal
// FEATURE::Terminal en 3D
typedef struct s_term
{ int curs[3];                      //Coordonnées du curseur :
                                    //(0, 1):terminal ; 2:x_coordonnée matrix
  int mous[3];                      //2:État et (0, 1):coordonnées de la souris
  int term[2];                      //Taille du terminal
  int wind[5];                      //Données sur la fenêtre :
                                    //(0, 1):coordonnées terminal;
                                    //(2, 3):taille;
                                    //4:x_coordonnée matrix;
  int size_max;                     //Longueur du fichier le plus long
  int nb_files;                     //Nombre de fichiers contenus
  int tmp;
  int nb_col;                       //Nombre de colonnes de fichiers
  t_tab **matrix;                   //Matrice de caractères
  int mat_size;                     //Longueur de la matrice
  char **tab_tri;                   //Tableau de tri des éléments
  int slide[3];                     //2:Longueur et (0, 1):coordonnées du slide
  char *finder;                     //Recherche intelligente
  int fine;                         //Curseur dans la barre de recherche
  t_map ***mapper; } t_term;        //Liste des fichiers
///3

///3
///De Hallo :)
///Fr Coucou :)
t_term *coucou_init(void);
void free_coucou(t_term *coucou);
void do_exit(t_term *coucou);
///3

///3
///De
///Fr Gestion des issues et réparations du programme
void select_cure(int type, char *prob);
void select_error(int type, char *prob);
void select_warning(int type, char *prob);
///3

///3
///De
///Fr Interactions avec le terminal grâce à ioctl(2) et aux caractères
///Fr d'échappements ("\033[...");
void term_init(int sig, t_term *coucou);
void term_coord(int *coord);
int *term_size(void);
void go_to(int x, int y);
void fleche_du_bas(t_term *coucou, int *coord);
void fleche_du_haut(t_term *coucou, int *coord);
void fleche_de_droite(t_term *coucou, int *coord);
void fleche_de_gauche(t_term *coucou, int *coord);
///3

///3
///De
///Fr
void get_names(char **argv, t_term *coucou);
void ttri_init(t_term *coucou, char **argv);
void remove_file(t_term *coucou, int *coord);
void command_line(t_term *coucou);
void get_size(int *size, t_term *coucou);
void free_mapper(t_term *coucou);
void put_result(t_term *coucou);
int find(t_term *coucou, char *buf);
///3

///3
///De
///Fr Manipulations de la matrice de caractères
void matrix_init(t_term *coucou);
void get_coords(int *coord, int *test, t_term *coucou);
void init_char(char c, t_tab *ceil, char attr[10][8]);
void free_matrix(t_tab **matrix);
///3

///3
///De
///Fr Manipulations de la fenêtre du programme
void init_wind(t_term *coucou);
void init_slide(t_term *coucou);
void windower(t_term *coucou);
void wind_clear(t_term *coucou);
void redimension(t_term *coucou, char buf[12]);
void deplacement(t_term *coucou, char buf[12]);
void wind_line(char *str, int i, int *j, t_tab **matrix);
void put_window(t_term *coucou, char (*buf)[12]);
void slide(t_term *coucou);
///3

///3
///De
///Fr Gestion des événements
int idle(char* buf, t_term *coucou);
int mouse(char *buf, t_term *coucou);
int fleche(char *buf, t_term *coucou);
void select_ret(t_term *coucou, int flag);
void content_use(void (*tab)(char*, t_term*));
void ft_signal(void);
///3

///3
///De
///Fr
void ft_tri(char **tab);
///3

#endif
