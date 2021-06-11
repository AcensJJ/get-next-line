<p align="center">
    <img alt="42-lyon" src="https://user-images.githubusercontent.com/45235527/106354618-6ec65a00-62f3-11eb-8688-ba9e0f4e77de.jpg" />
</p>

# get-next-line

<img alt="Note" src="https://user-images.githubusercontent.com/45235527/96751780-e4a25780-13cd-11eb-9d06-aa687ff25143.png" width="250" height="200" />

### <strong>Description</strong>

Qu'il s'agisse d'un fichier, de l'entrée standard, ou même plus tard d'une connexion réseau, vous aurez 
toujours besoin de lire du contenu ligne par ligne. Il est donc temps de vous attaquer à cette fonction, 
indispensable pour un certain nombre de vos prochains projets.


# Partie Obligatoire - Get_next_line

![Sujet](https://user-images.githubusercontent.com/45235527/96753205-d0f7f080-13cf-11eb-9730-1a2309c69664.png)

- Des appels successifs à votre fonction <strong>get_next_line</strong> doivent vous permettre de
lire l’entièreté du texte disponible sur le file descriptor, une ligne à la fois, jusqu’au
EOF.
- La libft n’est pas autorisée sur ce projet. Vous devez aujouter le fichier <strong>get_next_line_utils.c</strong>
qui contiendra les fonctions nécessaires au fonctionnement de votre get_next_line.
- Assurez-vous que votre fonction se comporte correctement lorsque vous lisez depuis
un fichier ou l’entrée standard.
- Votre programme doit compiler avec le flag <strong>-D BUFFER_SIZE=xx</strong> Ce define doit
être utilisé dans vos appels de read du get_next_line, pour définir la taille du
buffer. Cette valeur sera modifiée lors de l’évaluation et par la moulinette.
- Compilation : <strong>gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c
get_next_line_utils.c</strong>
- Votre read DOIT utiliser le BUFFER_SIZE pour lire depuis un fichier ou depuis
le stdin.
- Dans le fichier header <strong>get_next_line.h</strong>, vous devez avoir au moins le prototype
de la fonction.
- Nous considérons que <strong>get_next_line</strong> a un comportement indeterminé si, entre
deux appels, le file descriptor change de fichier alors qu’<strong>EOF</strong> n’a pas été atteint
sur le premier fichier.
- Non, <strong>lseek</strong> n’est pas une fonction autorisée. La lecture du file descriptor ne doit
être faite qu’une seule fois.
- Enfin, nous considérons que <strong>get_next_line</strong> a un comportement indeterminé si
nous lisons un fichier binaire. Cependant, si vous le souhaitez, vous pouvez rendre
ce comportement cohérent.
- Les variables globales sont interdites.


# Partie Bonus

Le projet get_next_line laisse peu de place à l’imagination, mais si vous avez complété 
entièrement la partie obligatoire, vous pouvez faire les bonus proposés ici.

- Completez get_next_line avec une seule variable statique.
- Completez get_next_line en lui permettant de gérer plusieurs fd. Par exemple, si
les fd 3, 4 et 5 sont accessibles en lecture, alors vous pouvez apeller get_next_line
une fois sur 3, puis sur 4, puis sur 5, puis le rapeller sur 3, etc. Sans jamais perdre
le contenu lu sur chacun des fd, et sans le mélanger.
