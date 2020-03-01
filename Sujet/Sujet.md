Le programme que vous devez implémenter est une simplification du jeu des petits chevaux qui s'appelle "les petits canassons".

Ce jeu se joue de la manière suivante :

Chacun des deux joueurs dispose de deux canassons qui sont au départ dans l'enclos associé au joueur. L'objectif est que chaque canasson fasse un tour de piste. Le joueur le plus jeune prend les pions jaunes et c'est lui qui commence.
Chaque joueur à son tour lance un dé (de 1 à 6) ce résultat doit être aléatoire, le joueur peut ensuite réaliser un mouvement parmi un ensemble de mouvements possibles. Il arrive qu'à certains tours aucun mouvement ne soit possible, à ce moment-là, on passe au joueur suivant.
Lorsqu'un 6 est tiré, le joueur peut choisir si il lui reste au moins un canasson dans son enclos de le sortir dans la case de couleur correspondante. Il devra ensuite attendre le tour suivant pour effectuer un autre mouvement. Si cette case est déjà occupée par un autre canasson, il ne pourra pas le sortir.
A chaque tour, un canasson peut avancer si le nombre de cases correspondantes à la valeur du dé sont disponibles. Si les deux canassons du joueur sont présents sur la piste, dans l'hypothèse où les deux peuvent se déplacer, le joueur doit pouvoir décider lequel il va déplacer.
Pour pouvoir terminer son tour de piste le canasson devra arriver exactement sur la case de départ du tour. Une fois arrivé sur cette case, le pion est écarté du jeu. Si la case est dépassée, le canasson devra faire un deuxième tour de piste.
Dans l'hypothèse où des mouvements sont possibles, l'utilisateur peut quand même choisir de ne rien faire. Pour ne pas dépasser la case de sortie par exemple. 
Afin de vous aider vous trouverez, dans le dossier "outils" 2 programmes que vous pouvez exécuter afin de mieux comprendre leur fonctionnement :

Le premier vous aide à comprendre la fonction random() : tirage aléatoire de nombre. Attention de bien ajouter la bibliothèque time.h ainsi que srand(time(NULL)) au début de votre main.
Le second concerne la fonction color qui vous permet d’utiliser de la couleur sur la console initialement en noir et blanc. Attention de bien ajouter la bibliothèque windows.h
Variantes :

Un canasson adverse peut être mangé si il se trouve sur la dernière position de déplacement ou sur la case de départ de l'adversaire dans l'hypothèse où celui-ci peut sortir. Un pion mangé retourne à son enclos et devra recommencer un tour de piste.
 
