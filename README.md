# TchatTCP

Ce projet codé en C est une application de messagerie qui permet à plusieurs utilisateurs de communiquer en temps réel via une connexion réseau fiable grâce à son protocole TCP qui assure une transmission fiable et ordonnée des messages entre les clients et le serveur.

Concrètement le serveur écoute sur un port spécifique et gère les connexions entrantes, tandis que les clients se connectent au serveur pour envoyer et recevoir des messages.

L'échange de donées se fait comme suit, les messages sont envoyés sous forme de paquets TCP et transmis de manière séquentielle, garantissant l'intégrité des données.