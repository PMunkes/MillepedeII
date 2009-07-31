#!/usr/bin32/python
#
import array
### read millepede binary file #################
#   print information
#
# input file
f = open("milleBinaryISN.dat","rb")
#
# number of records (tracks)
mrec = 10
#
### C. Kleinwort - DESY ########################

nrec=0

try:
    while (nrec<mrec):
# read 1 record    
        len=array.array('l')
        len.fromfile(f,1)
        nr=len[0]/2
        nrec+=1
        print " === NR ", nrec, nr

        glder=array.array('f')
        glder.fromfile(f,nr)

        inder=array.array('l')
        inder.fromfile(f,nr)

        i=0
        nh=0
        ja=0
        jb=0
        jsp=0
        nsp=0
        while (i<(nr-1)):
            i+=1
            while (i<nr) and (inder[i] != 0): i+=1
            ja=i
            i+=1
            while (i<nr) and (inder[i] != 0): i+=1
            jb=i
            i+=1
            while (i<nr) and (inder[i] != 0): i+=1
            i-=1
# special data ?
            if (ja+1 == jb) and (glder[jb] < 0.):
               jsp=jb
               nsp=int(-glder[jb])
               i+=nsp
               print ' ### spec. ', nsp, inder[jsp+1:i+1], glder[jsp+1:i+1]
               continue
            nh+=1           
            if (jb<i):
# measurement with global derivatives
               print ' -g- meas. ', nh, inder[jb+1], jb-ja-1, i-jb, glder[ja], glder[jb]
            else:
# measurement without global derivatives
               print ' -l- meas. ', nh, inder[ja+1], jb-ja-1, i-jb, glder[ja], glder[jb]            
            if (ja+1<jb):
               print " local  ",inder[ja+1:jb]
               print " local  ",glder[ja+1:jb]
            if (jb+1<i+1):
               print " global ",inder[jb+1:i+1]
               print " global ",glder[jb+1:i+1]
               
except EOFError:
     pass
#    print "end of file"

f.close()
