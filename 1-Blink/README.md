# Blink

## Introduction
Blink est la base du projet
<chapitre à completer>

## Schéma et fonctionnement
<img width="470" alt="schema" src="https://user-images.githubusercontent.com/9362475/146255138-48fa7efe-73d8-4522-916d-bba0fd86cd60.png">

Lorsque le circuit est fermé par le switch entre la pin 2 et le GND, le programme est en mode running et fait clignoter la LED intégrée (L).
Il renvoie également l'état des LED dans la sortie console.

Lorsque le cicuit est ouvert, le programme est en mode standby et ne fait rien en attendant que l'interrupteur soit actionné pour fermer de nouveau le curcuit.
Il renvoie également dans la sortie console qu'il est en standby.
