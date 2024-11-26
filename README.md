# Snake Game
Jogo criado com intuito de apresentar na faculdade para a cadeira de Programação Imperativa e Funcional

## Alunos
- Gabriel Reinaldo Roma
- Ícaro Barros
- Gabriel Ferreira Ferraz

# Compilação

No replit, abra o Shell e digite "make" e após o build do jogo, digite "make run"

# Lista de funções

loadRanking() = carregamento do ranking do jogo

saveRanking() = salvando os rankings gerados

addPlayerToRanking() = adiciona o jogador atual ao ranking

showRanking() = mostra o ranking das 3 melhores posicoes 

updateScore() = atualizacao do score (de 10 em 10)

initializeGame() = funcao base para inicializar o jogo 

endGame() = funcao base para fechar o jogo

initializeSnake() = inicializacao da cobra no mapa

freeSnake() = liberacao de memoria da cobra

generateFood() = geracao de comida em partes aleatorias do mapa

 drawFood() = desenho da comida
 
 drawSnake() = desenho da cobra
 
 drawBorders() = desenho das bordas do jogo
 
 moveSnake() = movimentacao base da cobra 
 
 handleInput() = atribuimos a movimentacao criada na funcao anterior para as teclas
 
 checkCollision() = colisao da cobra com parede ou ela mesma e caso tenha comido puxamos novamente a funcao generateFood 
 
 gameLoop() = loop do game, caso queira reiniciar 
 
 showMenu() = menu do jogo com as escolhas: jogar e sair

