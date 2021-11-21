using System;
using System.Collections.Generic;

namespace Strings1
{
    class Program
    {
        static string ValInLen(string s) => $"{(s.Length is < 4 or > 10 ? "NOT " : "")}OKAY ({s.Length})";
        static void Main(string[] args)
        {
            List<string> l = new() { "Pro", "Prog", "Programm", "Programmieren", "Programmieren Lernen" };
            l.ForEach(x => Console.WriteLine(ValInLen(x)));
        }
    }
}
