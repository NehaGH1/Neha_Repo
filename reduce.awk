BEGIN{num=0; nstep=100}
{
   if (num==nstep)
   {
      print $0;
      num=0;
   }
   num++;
}
