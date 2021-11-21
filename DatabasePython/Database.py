import sqlite3

#Erstellen der Datenbank
createDB = sqlite3.connect("mydatabase.db")
cursor = createDB.cursor()

#Erstellend der Tabelle
def createTable():
    cursor.execute("CREATE TABLE IF NOT EXISTS kunden (ID INTEGER PRIMARY KEY AUTOINCREMENT, namen TEXT, vorname TEXT, alterJahre REAL)")

#Einfügen der Daten in die Tabelle
def insertIntoDatabase():
    cursor.execute("INSERT INTO kunden (namen, vorname, alterJahre) VALUES ('TOM' , 'Huber', 22.3)")
    

#Lesen der Daten aus der Tabelle
def readFromDatabase():
    cursor.execute ("SELECT * FROM kunden")
    read = cursor.fetchall()
    print(read)
    
                               
createTable()    #erstellen der Tabelle                   
insertIntoDatabase()
readFromDatabase()

createDB.commit()