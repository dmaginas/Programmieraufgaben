# Lotto Zahlen vorschagen...
import random  
anzahl = 0
    
def zahlen(anzahl, a, e):
    liste = [0]
    while anzahl > 0:        
        z = (random.randint(a, e))  # 1, 49 od. 1, 10 Bereich
        liste.append(z)
        a1 = len(liste)
        liste = list(set(liste))    # doppelte entfernen 
        a2 = len(liste)
        
        if a1 > a2:
            anzahl += 1
            
        anzahl -= 1
            
    
    liste.sort()
    del liste [0]
    return liste



print('Zufallszahlen 6 aus 49:')
print('Gewinnzahlen', zahlen(6, 1, 49))
