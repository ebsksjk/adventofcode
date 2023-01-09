file = open("input.txt", "r")

x = 1
cycle = 0
cycles = [0]

for zeile in file.readlines():
    if("noop" in zeile):
        cycle += 1
        cycles.append(x)
        #print("cycle: ", cycle)
        #print("x: ", x)
        continue
    else:
        arg = int(zeile.split(' ')[1])
        #print("arg: ", arg)
        #print("cycle: ", cycle)
        #print("x: ", x)
        
        cycle +=1
        cycles.append(x)
        cycle +=1
        cycles.append(x) 
        x += arg

totalStrength = 0

for i in range(20, len(cycles), 40):
    print(cycles[i])
    print("signal strength at x: ", cycles[i] * i)
    totalStrength += (cycles[i] * i)

print("totalStrength: ", totalStrength)
print(len(cycles))