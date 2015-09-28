# Lem_in
 Algorithms &amp; AI, Imperative programming, Rigor

note finale :
97 / 100

• Votre programme va recevoir sur l’entrée standard la description de la fourmilière
pour la forme suivante :
nombre_de_fourmis
les_salles
les_tubes

• La fourmilière est décrite par ses liaisons :
##start
1 23 3
2 16 7
#commentaire
3 16 3
4 16 5
5 3 9
6 1 0
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#autre commentaire
4-2
2-1
7-6
7-2
7-4
6-5

• On a donc 2 parties :
◦ La définition des salles sous la forme suivante : nom coord_x coord_y
◦ La définition des tubes : nom1-nom2
◦ Le tout entre-coupé de commentaires qui commencent par #

• Les lignes commençant par un ## sont des commandes modifiant les propriétés de
la ligne significative qui vient juste après.

• Par exemple, ##start indique l’entrée de la fourmilière et ##end la sortie.

• La première ligne non conforme ou vide entraîne la fin de l’acquisition de la fourmilière
et son traitement normal avec les données déjà acquises.

• S’il n’y a pas assez de donnée pour faire un traitement normal vous devrez simplement
afficher ERROR


Le but de tout ca ?

• Le but du projet est de trouver le moyen le plus rapide de faire traverser la fourmilière
par n fourmis.

• Évidemment, il y a quelques contraintes. Pour arriver le premier, il faut prendre le
chemin le plus court (et pas forcément pour autant le plus simple), ne pas marcher
sur ses congénères, tout en évitant les embouteillages.

• Au début du jeu, toutes les fourmis sont sur la salle indiquée par la commande
##start. Le but est de les amener sur la salle indiquée par la commande ##end en
prenant le moins de tours possible. Chaque salle peut contenir une seule fourmi à
la fois (sauf ##start et ##end qui peuvent en contenir autant qu’il faut).

• On considère que les fourmis sont toutes dans la salle ##start au démarrage

• Vous n’afficherez à chaque tour que les fourmis qui ont bougé

• À chaque tour vous pouvez déplacer chaque fourmi une seule fois et ce suivant un
tube (la salle réceptrice doit être libre).

• Vous devez sortir le résultat sur la sortie standard sous la forme suivante :
nombre_de_fourmis
les_salles
les_tubes
Lx-y Lz-w Lr-o ...
Où x, z, r sont des numéros de fourmis (allant de 1 à nombre_de_fourmis) et
y, w, o des noms de salles.
