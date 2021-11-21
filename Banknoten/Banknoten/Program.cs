using System;

namespace Banknoten
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Gebe den Banknoten Code ein:");
            string Code = Console.ReadLine().Replace(" ", string.Empty).ToUpper();

            //Erfasse Ländercode
            int Land = Convert.ToInt32(Convert.ToChar(Code.Substring(0, 1))) - 64;
            Code = Code.Remove(0, 1);
            Code = Land.ToString() + Code;

            //Berechne die Quersumme
            int Quersumme = 0;
            for (int i = 0; i < Code.Length - 1; i++)
            {
                Quersumme += Int32.Parse(Convert.ToString(Code[i]));
            }

            int Rest = Quersumme % 9;
            if ((8 - Rest == 0 && Code.Substring(Code.Length - 1, 1) == "9") || (8 - Rest != 0 && Int32.Parse(Code.Substring(Code.Length - 1, 1)) == 8 - Rest))
                Console.WriteLine("Der Code ist richtig");
            else
                Console.WriteLine("Der Code ist falsch");

            Console.ReadLine();
        }
    }
}
