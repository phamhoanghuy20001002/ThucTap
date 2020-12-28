using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ThiHK
{
    class Program
    {
        List<XeLienTuyen> xlt = new List<XeLienTuyen>();
        public void nhap()
        {
            int n = 0;
            Console.WriteLine("nhap n: n>3");
            n = int.Parse(Console.ReadLine());
            FileStream f = new FileStream("thihk.txt", FileMode.Open);
            StreamReader rd = new StreamReader(f, Encoding.UTF8);
            for(int i = 0; i < n; i++)
            {
                string ve = rd.ReadLine();
                int tx = int.Parse(rd.ReadLine());
                int gia = int.Parse(rd.ReadLine());
                int dai = int.Parse(rd.ReadLine());
                string dt = rd.ReadLine();
                string lt = rd.ReadLine();
                XeLienTuyen t = new XeLienTuyen(ve, tx, gia, dai, dt, lt);
                xlt.Add(t);
            }
            foreach (var t in xlt)
            { Console.WriteLine(t.ToString()); }

        }
        public int demve()
        {
            Console.WriteLine("Nhap chieu dai tuyen: ");
            String x = Console.ReadLine();
            byte dem=0;
            for (int i = 0; i < xlt.Count; i++)
            {
                if (x.ToUpper().CompareTo(xlt[i].chieudai) == 0)
                {
                    Console.WriteLine(x.ToString());
                    dem++;

                }

            }
            return dem;
        }
        public void sapxep()
        {
            xlt.Sort();

        }
      
        static void Main(string[] args)
        {
            Program pr = new Program();
            try
            {
                pr.nhap();
                pr.sapxep();
                pr.demve();
            }
            catch
            {
                Console.WriteLine("ERROR!");
            }
            Console.ReadLine();
        }
    }
}
