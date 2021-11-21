def parallel(a):
    ''' Parallele Wiederstandsberechnung: 
        R = 1 / (1/R1 + 1/R2 + 1/R3 + ...) usw. Anzahl beliebig 
    '''
    p = 0
    for i in range(0, a):
        p = p + 1/w[i]
    return 1/p

def seriell():
    ''' Serielle Wiederstandsberechnung:
        R = R1 + R2 + ... usw. Anzahl beliebig 
    '''
    return sum(w)

w = []  # Wiederstandsliste

# Abfrage starten
a = int(input('Anzahl der einzelnen Widerstände? (2 oder 3): '))
art = input('parallel(p) oder seriell(s): ')

for i in range(0, a):
    w.append(float(input('Wiederstandswert {0}: '.format(i+1))))

# Berechnung / Ausgabe
if art == 'p':    print('Gesamtwiederstand parallel =', parallel(a))
if art == 's':    print('Gesamtwiederstand seriell =', seriell())
    
    