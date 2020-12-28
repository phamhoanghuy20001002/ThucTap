using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ThiHK
{
    class XeLienTuyen:Xebus,IComparable<XeLienTuyen>
    {
        string lotrinh;
        public XeLienTuyen(string ve , int tx , int gia , int dai , string dt ,string lt="") : base(ve, tx, gia, dai, dt)
        {
            lotrinh = lt;
        }
         public int CompareTo(XeLienTuyen e)
         {if (GiaBan() > e.GiaBan()) return 1;
             else if (GiaBan() == e.GiaBan()) return 0;
             else return -1;

         }
        public override string ToString()
        {

            return sove + "     " + tuyenxe +  "        " + chieudai + "      "+lotrinh+"       "+GiaBan();
        }
    }
}
