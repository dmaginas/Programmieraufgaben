using System;
using System.Linq;

namespace LottoZahlen
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rnd = new Random();
            int[] zahlen = new int[6];
            for (int i = 0; i < 6; i++)
            {
                int randomZahl = rnd.Next(1, 49);
                while (zahlen.Contains(randomZahl))
                    randomZahl = rnd.Next(1, 49);
                zahlen[i] = randomZahl;
            }

            Console.Write("Zufällige Lottozahlen: ");
            foreach (var zahl in zahlen)
                Console.Write(zahl + " ");
            Console.ReadLine();
        }
    }
}
