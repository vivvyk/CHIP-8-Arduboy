import numpy as np
import sys

def loadgame(filen, mem):
    '''
    Loads game file into text.
    '''
    binary_file = open(filen, "r+b") #File needs to be opened for reading and writing; binary mode
    for i, byte in enumerate(binary_file.read()):
        mem[0x200 + i] = ord(byte) #Converts byte to integer

    chip8_fontset = [
        0xF0, 0x90, 0x90, 0x90, 0xF0,
        0x20, 0x60, 0x20, 0x20, 0x70,
        0xF0, 0x10, 0xF0, 0x80, 0xF0,
        0xF0, 0x10, 0xF0, 0x10, 0xF0,
        0x90, 0x90, 0xF0, 0x10, 0x10,
        0xF0, 0x80, 0xF0, 0x10, 0xF0,
        0xF0, 0x80, 0xF0, 0x90, 0xF0,
        0xF0, 0x10, 0x20, 0x40, 0x40,
        0xF0, 0x90, 0xF0, 0x90, 0xF0,
        0xF0, 0x90, 0xF0, 0x10, 0xF0,
        0xF0, 0x90, 0xF0, 0x90, 0x90,
        0xE0, 0x90, 0xE0, 0x90, 0xE0,
        0xF0, 0x80, 0x80, 0x80, 0xF0,
        0xE0, 0x90, 0x90, 0x90, 0xE0,
        0xF0, 0x80, 0xF0, 0x80, 0xF0,
        0xF0, 0x80, 0xF0, 0x80, 0x80
        ]

        #Loads into memory
    for i in range(80):
        memory[i] = chip8_fontset[i]

    return memory

if __name__ == "__main__":
    memory = np.zeros(4096, dtype=np.uint8)
    game = loadgame(sys.argv[1], memory) #loadsgames

    for i, item in enumerate(game):
        if item != 0:
            print i, item

    gamefile = open("game.txt", "w")
    gamefile.writelines(["%s," % item  for item in game])