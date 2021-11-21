romZiff = ['I', 'V', 'X', 'L',  'C', 'D', 'M'  ]
romWert = [  1,   5,  10,  50,  100, 500, 1000 ]



def dec2rom(dec):

    rom = ""
    if dec > 3999:
        rom = "Zahl zu gross"
        return rom
    
    index = 0
    while dec > 0:
    
        tmp = ""
        ziffer = dec % 10
        
        if ziffer == 4:
            tmp += romZiff[index]
            tmp += romZiff[index+1]
    
        elif ziffer == 9:
            tmp += romZiff[index]
            tmp += romZiff[index+2]
        
        else: 
            if ziffer >= 5:
                tmp += romZiff[index+1]
                ziffer -= 5
            
            while ziffer > 0:
                tmp += romZiff[index]
                ziffer -= 1
        
        dec = dec // 10
        rom = tmp + rom
        index += 2
    
    return rom

    
def rom2dec(rom):

    dec     = 0
    lastVal = 0
    ziffern = rom.upper()

    for i in range( len(ziffern)-1, -1, -1 ):
        
        curVal = 0        
        for j in range( 0, len(romZiff) ):
            
            if ziffern[i] == romZiff[j]:
                curVal = romWert[j]
                break
    
        if curVal == 0:
            return -1
        
        elif curVal >= lastVal:
            dec += curVal
        
        else:
            dec -= curVal
        
        lastVal = curVal
    
    return dec


rom = "MCMLXVIII"
dec = 1968

print( rom, " => ", rom2dec(rom) )        
print( dec, " => ", dec2rom(dec) )