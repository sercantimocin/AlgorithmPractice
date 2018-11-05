using System;
using System.Linq;
using ArrayAndStrings;

namespace HasAllCharctersUnique
{
    class Program
    {
        static void Main(string[] args)
        {
            ISolutionLib solution = new SolutionLib();

            Console.WriteLine("1.1");
            var r = solution.HasAllCharacters_1_1("AAAAAABCDEFGHIJLMNOPQRSTUVWXYZZZZZ");
            Console.WriteLine(r);

            Console.WriteLine("1.2");
            solution.ReverseStr_1_2("sercan");

            var k = Console.ReadKey();
        }



    }
}
