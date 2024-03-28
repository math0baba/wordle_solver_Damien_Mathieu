# Projet wordle solver de Mathieu et Damien 

# Comment installer ?
Ouvrir le terminal ubuntu et taper la commande suivante :
```sh
git clone https://github.com/math0baba/wordle_solver_Mathieu_Damien.git
```

```sh
cd wordle_solver_Mathieu_Damien
```

# Comment compiler le programme ?
Pour compiler le programme, rendez vous à la racine du projet git. Ensuite entrez la commande suivante :
```sh
gcc -I include/ -o bin/solver src/solver.c src/fonction.c
```

# Comment exécuter le programme ?
Pour exécuter le programme, rendez vous dans le dossier bin en tapant la commande :
```sh
cd bin
```
Puis entrez la commande :
```sh
./solver 
```
# Explication du projet
Le projet consiste à reproduire le jeu wordle qui consiste à deviner un mot mystère et de rajouter des filtres pour aider le joueur à trouver le mot mystère. 
Pour cela, le projet est diviser en 4 dossier :
un dossier bin qui contient les fichiers exécutables, un dossier include qui contient les headers, un dossier src qui contient deux fichiers C. Le premier fichier est le fichier solver.c qui contient la fonction principale. Le deuxième fichier est le fichier fonction.c qui contient toutes les fonctions. Enfin, on a le dossier ressources qui contient le fichier texte contenant la base de donnée du jeu.


  
