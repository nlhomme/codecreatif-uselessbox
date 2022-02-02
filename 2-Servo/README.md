# Le ServoMoteur
(Le fichier s'appelle Blink à cause de restrictions du logiciel Arduino)

## Introduction
Servo Moteur est la seconde partie du projet

## Schéma et fonctionnement
![Schéma](readme-files/diagram.png)

Lorsque le circuit est fermé par le switch entre la pin 2 et le GND, le programme est en mode running et fait clignoter la LED intégrée (L).
Il renvoie également l'état des LED dans la sortie console.

Lorsque le cicuit est ouvert, le programme est en mode standby et ne fait rien en attendant que l'interrupteur soit actionné pour fermer de nouveau le curcuit.
Il renvoie également dans la sortie console qu'il est en standby.

La nouveauté ici est qu'il y a un servomoteur, au bout duquel sera à terme vissé ou collé un doigt.
Ce doigt, entraîné par le servomoteur, va soulever le couvercle du boîtier puis actionner le bouton en façade.

A ce stade, nous pouvons établir le fonctionnement de la boîte inutile:
* Le servomoteur se trouve au point initial (0)
* L'utilisateur actionne l'interrupteur, ce qui va désactiver le mode standby de l'Arduino
* Le servomoteur va s'enclencher, et ententraîner le doigt qui va soulever le couvercle puis actionner l'interrupteur
* Le programme passe alors en mode standby puis le servomoteur va retrouver sa position initiale (0), le doigt retournera dans le boîtier en fermant le couvercle
* Le programme de l'Arduino attend qui l'utilisateur actionne de nouveau l'interrupteur
Et ainsi de suite
