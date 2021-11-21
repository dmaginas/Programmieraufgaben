using System;

namespace ChuckALuck
{
    class Program
    {
			static void Main()
			{
				Random rnd = new Random();
				int runde = 1, kapital = 1000;

				for (;
					runde <= 1000 && kapital > 0;
					runde++)
				{

					kapital--;

					for (int i = 0; i < 3; i++)
						if (rnd.Next(1, 7) == 6) kapital++;
				}

				Console.WriteLine("Das Spiel wurde in Runde {0} mit {1} Euro Kapital beendet", --runde, kapital);

				Console.ReadKey(true);
			}
		}
}
