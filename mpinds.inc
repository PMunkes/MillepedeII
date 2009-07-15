
      INTEGER IGLBV,IGLBC,IGMAT,IGVEC,IGLMA,ICORM,ICORV,IAUX1,IDUX1,
     +        IDUX2,IDUX3,IDUX4,IDUX5,IDUX6,IDUX7,IDUX8,IDUX9,ISOLV
      EQUIVALENCE (INDU,IGLBV) ! initial global parameter values
      EQUIVALENCE (INDV,IGLBC) ! corrections to parameter values
      EQUIVALENCE (INDJ,IGMAT) ! big matrix double precision
      EQUIVALENCE (INDF,IGVEC) ! big vector double precision
      EQUIVALENCE (INDG,IGLMA) ! big vector double precision
      EQUIVALENCE (INDH,ICORM) ! corr matrix double precision
      EQUIVALENCE (INDI,ICORV) ! corr vector double precision
      EQUIVALENCE (INDK,IAUX1) ! vector single precision
      EQUIVALENCE (INDL,IDUX1) ! vector double precision
      EQUIVALENCE (INDM,IDUX2) ! vector double precision
      EQUIVALENCE (INDN,IDUX3) ! vector double precision
      EQUIVALENCE (INDO,IDUX4) ! vector double precision
      EQUIVALENCE (INDP,IDUX5) ! vector double precision
      EQUIVALENCE (INDQ,IDUX6) ! vector double precision
      EQUIVALENCE (INDR,IDUX7) ! vector double precision
      EQUIVALENCE (INDT,IDUX8) ! vector double precision
      EQUIVALENCE (IND6,IDUX9) ! vector double precision
      EQUIVALENCE (INDS,ISOLV) ! vector double precision
 
      PARAMETER (NDIMB=5000)
      COMMON/MEMI/NST,GLDER(NDIMB),INDER(NDIMB)

      PARAMETER (MFILES=500)
      INTEGER MFD(MFILES)  ! MFD(.)=1 binary   MFD(.)=2 text
      INTEGER LFD(MFILES)  ! LFD(.)=  number of characters
      INTEGER NFD(MFILES)  ! NFD(.)=  index in file  
      CHARACTER*500 TFD(MFILES)        ! file names
      COMMON/MPFILE/IFILE,NFILES,NFILB,NFILC,MFD,LFD,TFD,NFD

      INTEGER NTGB,NVGB,NAGB,NCGB,NAGBN,NALCN,
     +        METSOL,MATSTO,MPRINT,MDEBUG,MREQEN,INTRAC,
     +        MITERA,MBANDW,ICTEST,NAEQN,NREC,NLOOPN,
     +        LUNKNO,LHUBER,NREJEC,
     +        ITERAT,NTERAT,
     +        NRECPR,NRECP2,NREC1,NREC2,
     +        ISUBIT,NHISTP,
     +        NOFEAS,
     +        NDFSUM,NREGUL,IITERA,ISTOPA,
     +        LSINFO,ITEXIT,ICALCM,MATRIT,NPRESG,NRECAL,NMISS1,ISAVES
      REAL
     +        CHIREM,DFLIM,
     +        TIMES,GBM,UBM,STEPL,
     +        VALUE1,VALUE2,
     +        TA,DWCUT,
     +        WOLFC1,WOLFC2,DELFUN,ACTFUN,ANGRAS,
     +        REGULA,REGPRE,DELTIM,RSTART

      LOGICAL RECPRI,NEWITE
      DOUBLE PRECISION MRESTL,CHICUT
      COMMON/MPSTER/MRESTL,CHICUT,
     +              NTGB,NVGB,NAGB,NCGB,NAGBN,NALCN,
     +              METSOL,MATSTO,MPRINT,MDEBUG,MREQEN,INTRAC,
     +              MITERA,MBANDW,ICTEST,NAEQN,NREC,NLOOPN,
     +              LUNKNO,LHUBER,CHIREM,CHHUGE,DFLIM,NREJEC(3),
     +              ITERAT,NTERAT,TIMES(0:6),GBM,UBM,STEPL,
     +              NRECPR,NRECP2,NREC1,NREC2,VALUE1,VALUE2,
     +              RECPRI,NEWITE,TA(2),DWCUT,ISUBIT,NHISTP,
     +              WOLFC1,WOLFC2,NOFEAS,DELFUN,ACTFUN,ANGRAS,
     +              NDFSUM,NREGUL,REGULA,REGPRE,IITERA,DELTIM,ISTOPA,
     +              LSINFO,ITEXIT,ICALCM,RSTART,MATRIT,NPRESG,NRECAL,
     +              NMISS1,ISAVES
*     MRESTL= tolerance criterion for MINRES (default 10^-8) (GF)
*     NTGB  = total number of global parameters (incl. fixed)
*     NVGB  = number of variable parameters
*     NAGB  = number of fit parameters (incl. Lagrange multiplier)
*     NCGB  = number of constraints  
*     NSPR  = dimension of sparse matrix array 
*     NAGBN = max number of global parameters in a record
*     NALCN = max number of local parameters in a record
*     NAEQN = max number of equations in a record
*     NREC  = record number 
*     NLOOPN= number of LOOPN call
*     LUNKNO= flag for unkown keuwords
*     LHUBER= flag for Huber outlier down-weighting  
*     CHICUT= rejection in first iteration
*     CHIREM= rejection after first iteration
*     CHHUGE= 'huge' rejection always applied (GF)
*     DFLIM = delta F limit for convergence
*     NREJEC(3) = counter for rejected cases
*     ITERAT= iteration in solution
*     NTERAT= number of iterations
*     TIMES(0:5)=times for textreading(0), LOOP11(1), LOOP2(2),
*             first LOOPN(3), other LOOPN(4),
*             first solution(5), other solutions(6) 
*     GBM    = total space in Gbyte
*     UBM    = used space in Gbyte
*     STEPL  = step factor in lines search
*     NRECPR = number of record to be printed
*     NRECP2 = number of record to be printed 
*     NREC1  = record number with largest residual
*     NREC2  = record number with largest chi^2/Ndf
*     VALUE1 = largest residual
*     VALUE2 = largest chi^2/Ndf
*     RECPRI = record-print flag
*     NEWITE = new iteration
*     TA(2)  = array for ETIME
*     DWCUT  = cut on downweight fraction
*     ISUBIT = subito flag - finish after one-step
*     NHISTP = histogram print flag 
*     WOLFC1 = C_1 constant of strong Wolfe condition (default 10^-4)
*              0 < C_1 < C_2 < 1   
*     WOLFC2 = C_2 constant of strong Wolfe condition
*              default = 0.9 for Newton and quasi Newton
*              default = 0.1 for nonlinear CG

*     NOFEAS = do not make par feasible at start, if ne zero
*     DELFUN = expected function change for search step
*     ACTFUN = actual function change 
*     ANGRAS = angle between gradient and search direction, in degrees 
*     METSOL = solution method
*     MATSTO = matrix storage mode
*     MPRINT = print flag
*     MDEBUG = debug flag
*     MREQEN = min number of entries
*     INTRAC = 0 batch, =1 interactive
*     MITERA = number of iterations
*     NPRESG = number of presigmas 
*     NRECAL = total number of records 
*     NMISS1 = rank defect for constraints
*     MBANDW = width of band matrix 
*     ICTEST = 1 for internal test data
*     NDFSUM = sum of all NDFs
*     NREGUL = 1 for regularization
*     REGULA = regularization factor
*     REGPRE = default pre-sigma      
*     IITERA = number of internal (GMRES) iterations
*     DELTIM = delta time
*     RSTART = start time
*     ISTOPA = stop code of solution
*     LSINFO = INFO from line search
*     ITEXIT = exit code
*     ICALCM = 

      DOUBLE PRECISION FVALUE,FLINES
      COMMON/MPDOUB/FVALUE,FLINES

*     statement functions to get from the total parameter index the ... 
      INTEGER JTGBL,JVGBI,JTGBI,IJSYM,ITGBI,IVGBI,I,J
      JTGBL(ITGBI)=MQ(INDA+ITGBI+ITGBI-1) ! ... total parameter label
      JVGBI(ITGBI)=MQ(INDA+ITGBI+ITGBI)   ! ... variable-parameter index 
      JTGBI(IVGBI)=MQ(IND3+IVGBI)         ! ... total parameter index
      IJSYM(I,J)=MIN(I,J)+(MAX(I,J)*MAX(I,J)-MAX(I,J))/2


