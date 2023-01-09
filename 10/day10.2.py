def printScreen(liste):
    for y in range(0, 6):
        print(y, end=': ')
        for x in range(0, 40):
            print(liste[y * 40 + x], end='')
        print('\n')
        
def moveSprite(x, old_x):
    global vram
    
    vram[old_x - 1] = 0
    vram[old_x] = 0
    vram[old_x + 1] = 0
    
    vram[x - 1] = 1
    vram[x] = 1
    vram[x + 1] = 1

##################################

screen = ['.'] * (40*6) 
vram   = [0] * (40*6)

regx = 1
pause = 0
arg = 0

cycle = 0

inhalt = open("input.txt", "r")

moveSprite(1, 1)
#printScreen(vram)

y = 0
while True:
    if(cycle > 239):
        break
    
    print("cycle: ", cycle)
    print("x: ", regx)
    print("total x: ", regx + (40*y))
    print("y:", y)
    print("pause: ", pause)
    print("sprite at cycle: ", vram[cycle])
    
    if(pause == 0):        
        regx  += arg
        
        moveSprite(regx + (40*y), (regx+ (40*y)) - arg)
        
        arg = 0
        
        line = inhalt.readline()
        print(line, end=' ')
        if line == '':
            break
        if("noop" in line):
            pass
        else:
            arg = int(line.split(' ')[1])
            pause = 1
    else:
        pause = pause - 1
    
    if(vram[cycle] == 1):
        screen[cycle] = 'X'
    else: 
        screen[cycle] = '.'
    cycle += 1
    
    y = cycle // 40

printScreen(screen)
#printScreen(vram)