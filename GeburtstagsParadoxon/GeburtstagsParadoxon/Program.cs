// NET Core 3.x

using System.Linq;
using static System.Linq.Enumerable;
using static System.Console;
using static System.Math;

namespace GeburtstagsParadoxon
{
    class Program
    {
        static void Main()
        {
            const double Prob = 50.0;
            WriteLine($"Eine Wahrscheinlichkeit von {Prob}% liegt ab {GetNumOfPers(Prob)} Personen vor.\n");
            Range(5, 95).Where(x => x % 5 == 0).ToList().ForEach(x => WriteLine($"{x,2}%: {GetNumOfPers(x),2} Pers"));
        }
        static double GetProb(int n) => (Pow(365, n) - Range(365 - n + 1, n).Aggregate(1.0, (x, y) => x * y)) / Pow(365, n) * 100;
        static int GetNumOfPers(double p) => Range(1, 365).Where(x => GetProb(x) >= p).FirstOrDefault();
    }
}
