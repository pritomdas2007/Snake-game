import pygame
from pygame.locals import *
import time
import random
SIZE = 30

class Apple:
    def __init__(self,parent_screen):
        self.parent_screen = parent_screen
        self.image = pygame.image.load("apple.png").convert()
        self.image = pygame.transform.scale(self.image, (30, 30))   
        self.x = 120
        self.y = 120
    def draw(self):
        self.parent_screen.blit(self.image, (self.x, self.y))
        pygame.display.flip()
    def move(self):
        self.x = random.randint(1,32)*SIZE
        self.y = random.randint(1,15)*SIZE



class Snake:
    def __init__(self, parent_screen,length):
        self.parent_screen = parent_screen
        self.block = pygame.image.load("bloc.png.jpeg").convert()   # loads the image of block
        self.block = pygame.transform.scale(self.block, (30, 30))   # Resize block
        self.x = 200                                                # initial position
        self.y = 200
        self.direction = 'down'                                     # initially it moves down

        self.length=length
        self.x = [SIZE]*length
        self.y = [SIZE]*length

    def draw(self):
        self.parent_screen.fill((0,204,0))                    # Background color

        for i in range(self.length):
             self.parent_screen.blit(self.block, (self.x[i], self.y[i]))
        pygame.display.flip()

    def move_up(self):
        self.direction = 'up'                                       # it will move constantly
                                                                    #in one direction if not any button change                                                                  
    def move_down(self):
        self.direction = 'down'
        
    def move_left(self):
        self.direction = 'left'
        
    def move_right(self):
        self.direction = 'right'


    def walk(self):
        for i in range(self.length-1,0,-1):
            self.x[i] = self.x[i-1]                                #update body
            self.y[i] = self.y[i-1]
            
        if self.direction == 'left':                               #update head
            self.x[0] -= SIZE
        elif self.direction == 'right':
            self.x[0] += SIZE
        elif self.direction == 'up':
            self.y[0] -= SIZE
        elif self.direction == 'down':
            self.y[0] += SIZE

        self.draw()
        
    def increase_length(self):
        self.length += 1
        self.x.append(-1)
        self.y.append(-1)

class Game:
    def __init__(self):
        pygame.init()
        self.surface = pygame.display.set_mode((1000, 500))       #display screen size
        pygame.display.set_caption("Snake Game")
        self.snake = Snake(self.surface,1)
        self.snake.draw()
        self.apple = Apple(self.surface)
        self.apple.draw()

    def reset(self):
        self.snake = Snake(self.surface,1)
        self.apple = Apple(self.surface)
    
    def is_collision(self, x1, y1, x2, y2):
        if x1 >= x2 and x1 < x2 + SIZE:
            if y1 >= y2 and y1 < y2 + SIZE:
                return True
        return False

    def score(self):
        font = pygame.font.SysFont('arial',30)
        score = font.render(f"Score: {self.snake.length}",True,(0,0,0))
        self.surface.blit(score,(850,10))

    def show_game_over(self):
        self.surface.fill((0,204,0))
        font = pygame.font.SysFont('arial', 30)
        line1 = font.render(f"Game is over! Your score is {self.snake.length}", True, (0, 0, 0))
        self.surface.blit(line1, (200, 300))
        line2 = font.render("To play again press Enter. To exit press Escape!", True, (0, 0, 0))
        self.surface.blit(line2, (200, 350))

        pygame.display.flip()


    def play(self):
        self.snake.walk()
        self.apple.draw()
        self.score()
        pygame.display.flip()

        if self.is_collision(self.snake.x[0], self.snake.y[0], self.apple.x, self.apple.y):                   #Collision with apple         #checks if the apple collides with snake's head
            self.snake.increase_length()
            self.apple.move()
            
        for i in range(2, self.snake.length):
            if self.is_collision(self.snake.x[0], self.snake.y[0], self.snake.x[i], self.snake.y[i]):         #Collision with its body
                raise "Collision Occured"

    def run(self):
        running = True
        pause = False
        while running:
            for event in pygame.event.get():
                if event.type == KEYDOWN:
                    if event.key == K_ESCAPE:
                        running = False
                    if event.key == K_RETURN:
                        pause = False

                        
                    if not pause:
                       if event.key == K_UP:
                        self.snake.move_up()
                        
                       if event.key == K_DOWN:
                        self.snake.move_down()
                        
                       if event.key == K_LEFT:
                        self.snake.move_left()
                        
                       if event.key == K_RIGHT:
                        self.snake.move_right()

                elif event.type == QUIT:
                    running = False
            try:

                if not pause:
                    self.play()

            except Exception as e:
                self.show_game_over()
                pause = True
                self.reset()        

           
            time.sleep(0.2)


if __name__ == "__main__":
    game = Game()
    game.run()
