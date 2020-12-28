using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ThiHK
{
    class Xebus
    {
        public string sove;
        public int tuyenxe;
        public int giasan;
        public int chieudai;
        public string doituong;
        public Xebus(string ve = "", int tx = 0,int gia=0,int dai=0,string dt = "")
        {
            sove = ve; tuyenxe = tx;giasan = gia;chieudai = dai;doituong = dt;
        }
       
        
        public float GiaBan()
        {
            if (chieudai < 10)
            {
                return giasan;
            }
            else
                return giasan*giasan * 120 / 100;
        }
        
        public override string ToString()
        {
         
            return sove+"     "+tuyenxe+"    "+giasan+"        "+chieudai+"      ";
        }

    }
}
