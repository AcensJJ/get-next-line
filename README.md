# get-next-line

![Screenshot 2020-10-21_18-45-38-835](https://user-images.githubusercontent.com/45235527/96751780-e4a25780-13cd-11eb-9d06-aa687ff25143.png)

Description

Qu'il s'agisse d'un fichier, de l'entrée standard, ou même plus tard d'une connexion réseau, vous aurez 
toujours besoin de lire du contenu ligne par ligne. Il est donc temps de vous attaquer à cette fonction, 
indispensable pour un certain nombre de vos prochains projets.

![image](https://user-images.githubusercontent.com/45235527/96756036-c3446a00-13d3-11eb-9075-fd5b220d63cf.png)


# Partie Obligatoire - Get_next_line

![Screenshot 2020-10-21_19-00-47-804](https://user-images.githubusercontent.com/45235527/96753205-d0f7f080-13cf-11eb-9730-1a2309c69664.png)

- Des appels successifs à votre fonction get_next_line doivent vous permettre de
lire l’entièreté du texte disponible sur le file descriptor, une ligne à la fois, jusqu’au
EOF.
- La libft n’est pas autorisée sur ce projet. Vous devez aujouter le fichier get_next_line_utils.c
qui contiendra les fonctions nécessaires au fonctionnement de votre get_next_line.
- Assurez-vous que votre fonction se comporte correctement lorsque vous lisez depuis
un fichier ou l’entrée standard.
- Votre programme doit compiler avec le flag -D BUFFER_SIZE=xx Ce define doit
être utilisé dans vos appels de read du get_next_line, pour définir la taille du
buffer. Cette valeur sera modifiée lors de l’évaluation et par la moulinette.
- Compilation : gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c
get_next_line_utils.c
- Votre read DOIT utiliser le BUFFER_SIZE pour lire depuis un fichier ou depuis
le stdin.
- Dans le fichier header get_next_line.h, vous devez avoir au moins le prototype
de la fonction.
- Nous considérons que get_next_line a un comportement indeterminé si, entre
deux appels, le file descriptor change de fichier alors qu’EOF n’a pas été atteint
sur le premier fichier.
- Non, lseek n’est pas une fonction autorisée. La lecture du file descriptor ne doit
être faite qu’une seule fois.
- Enfin, nous considérons que get_next_line a un comportement indeterminé si
nous lisons un fichier binaire. Cependant, si vous le souhaitez, vous pouvez rendre
ce comportement cohérent.
- Les variables globales sont interdites.


# Partie Bonus

Le projet get_next_line laisse peu de place à l’imagination, mais si vous avez complété 
entièrement la partie obligatoire, vous pouvez faire les bonus proposés ici. Rendez
les 3 fichiers initiaux _bonus pour cette partie.

- Completez get_next_line avec une seule variable statique.
- Completez get_next_line en lui permettant de gérer plusieurs fd. Par exemple, si
les fd 3, 4 et 5 sont accessibles en lecture, alors vous pouvez apeller get_next_line
une fois sur 3, puis sur 4, puis sur 5, puis le rapeller sur 3, etc. Sans jamais perdre
le contenu lu sur chacun des fd, et sans le mélanger.
