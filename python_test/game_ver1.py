import os, pygame
from pygame.locals import *
from pygame.compat import geterror

if not pygame.font:
    print("Warning, fonts disable")
    
if not pygame.mixer:
    print("Warning, sound disable")
    
main_dir = os.path.split(os.path.abspath(__file__))[0]
data_dir = os.path.join(main_dir, "data")

def main():
    pygame.init()
    screen = pygame.display.set_mode((468, 500))
    pygame.display.set_caption("ver1")
    pygame.mouse.set_visible(0)

    # Create The Backgound
    background = pygame.Surface(screen.get_size())
    background = background.convert()
    background.fill((250, 250, 250))
    going = True
    while going:
        print("Warning, fonts disable")
    pygame.quit()
if __name__ == "__main__":
    main()