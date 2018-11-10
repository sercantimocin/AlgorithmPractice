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
            var r = solution.IsUniqueAllChars_1_1("sercan");
            Console.WriteLine(r);

            Console.WriteLine("1.2");
            solution.ReverseStr_1_2("sercan");

            Console.WriteLine("1.3");
            solution.RemoveDuplicateChars_1_3("sercean");

            var k = Console.ReadKey();
        }
    }
}
