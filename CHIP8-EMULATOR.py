import pygame
import CHIP8CPUCORE as cpu
import sys
import time
import loaded_game as lg

#Tutorial credit: http://www.multigesture.net/articles/how-to-write-an-emulator-chip-8-interpreter/


def loadgame(filen):
    '''
    Loads game file into memory.
    '''
    binary_file = open(filen, "r+b") #File needs to be opened for reading and writing; binary mode
    for i, byte in enumerate(binary_file.read()):
        cpu.memory[0x200 + i] = ord(byte) #Converts byte to integer
        #cpu.mem_change.add(0x200 + i)

    print type(cpu.memory[0x200])

if __name__ == "__main__":
    pygame.init()

    chip8 = cpu.chip8core() #object
    chip8.initialize() #Initializes cpu components

    #loadgame(sys.argv[1]) #loadsgames
    cpu.memory = lg.mem
    sleep_counter = 0

    while True:

        #Emulation loop
        chip8.execute_opcode()
        chip8.setkeys()

        if cpu.drawflag:
            #Update screen
            scsurf = pygame.transform.scale(cpu.surf, (1024, 512))
            cpu.window.blit(scsurf, (0, 0))
            pygame.display.update()

        sleep_counter += 1

        if sleep_counter == 40:
            #Delay
            sleep_counter = 0
            time.sleep(0.002)
