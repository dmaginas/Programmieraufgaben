using System;
using System.Collections.Generic;
using System.Linq;

namespace AethiopischesMultiplizieren
{
    class Program
    {
        static void Main(string[] args)
        {
            string antwort;
            List<int> Ende = new List<int>();
            List<int> Left = new List<int>();
            int links = 0;
            do
            {
                Ende.Clear();
                Left.Clear();

                //Eingabe der linken Seite
                do
                {
                    Console.Write("links ");
                    string linkss = Console.ReadLine();
                    bool versuch = int.TryParse(linkss, out links);
                    if (links < 0)
                    {
                        Console.WriteLine("Die Eingabe darf nicht kleiner als Null sein.");
                    }
                    if (!int.TryParse(linkss, out links))
                    {
                        Console.WriteLine("Nur die Eingabe von Zahlen ist möglich.");
                        links = -1;
                    }

                } while (links < 0);

                Console.WriteLine("\t" + "x");

                int rechts = 0;

                // Eingabe der rechten Seite

                do
                {
                    Console.Write("rechts ");
                    string rechtss = Console.ReadLine();
                    bool versuch = int.TryParse(rechtss, out rechts);
                    if (rechts < 0)
                    {
                        Console.WriteLine("Die Eingabe darf nicht kleiner als Null sein.");
                    }
                    if (!int.TryParse(rechtss, out rechts))
                    {
                        Console.WriteLine("Nur die Eingabe von Zahlen ist möglich.");
                        rechts = -1;
                    }
                } while (rechts < 0);

                Console.WriteLine();
                Console.WriteLine(links + "\t" + rechts);

                //Berechnung und erstes Einlagern in Containern
                while (links != 1)
                {

                    Ende.Add(rechts);
                    Left.Add(links);
                    links = links / 2;
                    rechts = rechts * 2;
                    Console.WriteLine(links + "\t" + rechts);

                }


                //herausfiltern aller Zahlen die durch 2 teilbar sind.
                int schleife = 0;

                while (schleife <= 2)
                {
                    for (int i = 0; i < Left.Count; i++)
                    {
                        if (Left[i] % 2 == 0)
                        {
                            Left.RemoveAt(i);
                            Ende.RemoveAt(i);
                        }
                    }
                    schleife++;
                }
                Ende.Add(rechts);
                Left.Add(1);

                //Ausgabe der aufzuaddierenden Zahlen
                Console.WriteLine();
                Console.WriteLine("Aufzuaddierende Zahlen:");
                for (int i = 0; i < Left.Count; i++)
                {
                    Console.WriteLine(Left[i] + "\t " + Ende[i]);
                }

                //Ausgabe der Gesamtsumme
                Console.ForegroundColor = ConsoleColor.White;
                Console.BackgroundColor = ConsoleColor.DarkRed;
                Console.WriteLine(Ende.Sum());
                Console.ResetColor();
                Console.Write("Noch ein Versuch ?");
                antwort = Convert.ToString(Console.ReadLine());
            } while (antwort == "j" || antwort == "ja");
        }
    }
}
