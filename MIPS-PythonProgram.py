import os
import sys

filename = 'swan.txt'
filename1 = 'swan1.txt'
lines = []

def WhichResister(a,b,c,d,e):
    S = [a,b,c,d,e]
    a= "".join(map(str, S))
    b= int(a, base=2)
    fh1.write ("R%d  "%b)

def base(a,b,c,d,e):
    S = [a,b,c,d,e]
    a= "".join(map(str, S))
    b= int(a, base=2)
    fh1.write ("(R%d)"%b)

def index(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z):
    S = [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z]
    a= "".join(map(str, S))
    b= int(a, base=2)
    fh1.write ("#%d"%b)

def offset(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p):
    Z = [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p]
    X = "".join(map(str, Z))
    Y= int(X, base=2)
    if a == 0:
        fh1.write ("#%d  "%Y)
    else:
        Q = ~Y
        A = 65537+Q
        fh1.write ("#-%d  "%A)

fh = None
fh1 = None
Add = 496
try:
    fh = open(filename)
    fh1 = open(filename1, "w")
    for line in fh:
        if line.strip():
            lines.append(line)
            print(line)
            for i in range(0,6):
                 fh1.write(line[i])
            fh1.write(' ')
            for i in range(6,11):
                 fh1.write(line[i])
            fh1.write(' ')
            for i in range(11,16):
                 fh1.write(line[i])
            fh1.write(' ')
            for i in range(16,21):
                 fh1.write(line[i])
            fh1.write(' ')
            for i in range(21,26):
                 fh1.write(line[i])
            fh1.write(' ')
            for i in range(26,32):
                 fh1.write(line[i])
            fh1.write('\t')
            fh1.write("%d"%Add)
            Add = Add + 4
            fh1.write('\t')

        if int(line[0])==0 and int(line[1])==0 and int(line[2])==0 and int(line[3])==0 and int(line[4])==0 and int(line[5])==0 \
                and int(line[11])==0 and int(line[12])==0 and int(line[13])==0 and int(line[14])==0 and int(line[15])==0 \
                and int(line[16])==0 and int(line[17])==0 and int(line[18])==0 and int(line[19])==0 and int(line[20])==0 \
                and int(line[26])==0 and int(line[27])==0 and int(line[28])==1 and int(line[29])==0 and int(line[30])==0 and int(line[31])==0 : # JR type instructions
            fh1.write("JR   ")
            WhichResister(int(line[6]),int(line[7]),int(line[8]),int(line[9]),int(line[10]))


        elif int(line[0])==0 and int(line[1])==0 and int(line[2])==0 and int(line[3])==0 and int(line[4])==0 and int(line[5])==0 \
                and int(line[6])==0 and int(line[7])==0 and int(line[8])==0 and int(line[9])==0 and int(line[10])==0 \
                and int(line[11])==0 and int(line[12])==0 and int(line[13])==0 and int(line[14])==0 and int(line[15])==0 \
                and int(line[16])==0 and int(line[17])==0 and int(line[18])==0 and int(line[19])==0 and int(line[20])==0 \
                and int(line[26])==0 and int(line[27])==0 and int(line[28])==0 and int(line[29])==0 and int(line[30])==0 and int(line[31])==0 : # NOP type instructions
            fh1.write("NOP  ")

        elif int(line[0])==0 and int(line[1])==0 and int(line[2])==0 and int(line[3])==0 and int(line[4])==0 and int(line[5])==0 \
                and int(line[6])==0 and int(line[7])==0 and int(line[8])==0 and int(line[9])==0 and int(line[10])==0 \
                and int(line[11])==0 and int(line[12])==0 and int(line[13])==0 and int(line[14])==0 and int(line[15])==0 \
                and int(line[16])==0 and int(line[17])==0 and int(line[18])==0 and int(line[19])==0 and int(line[20])==0 \
                and int(line[26])==0 and int(line[27])==0 and int(line[28])==1 and int(line[29])==1 and int(line[30])==0 and int(line[31])==1 : # BREAK type instructions
            fh1.write("BREAK  ")

        elif int(line[0])==0 and int(line[1])==0 and int(line[2])==0 and int(line[3])==0 and int(line[4])==0 and int(line[5])==0 and int(line[6])==0 \
                and int(line[7])==0 and int(line[8])==0 and int(line[9])==0 and int(line[10])==0: # Special case R type instructions
            print("this is R type Instruction")

            if int(line[26])==0 and int(line[27])==0 and int(line[28])==0 and int(line[29])==0 and int(line[30])==0 and int(line[31])==0 :
                    fh1.write("SLL   ")
            elif int(line[26])==0 and int(line[27])==0 and int(line[28])==0 and int(line[29])==0 and int(line[30])==1 and int(line[31])==0 :
                    fh1.write("SRL   ")
            elif int(line[26])==0 and int(line[27])==0 and int(line[28])==0 and int(line[29])==0 and int(line[30])==1 and int(line[31])==1 :
                    fh1.write("SRA   ")

            WhichResister(int(line[16]),int(line[17]),int(line[18]),int(line[19]),int(line[20]))
            WhichResister(int(line[11]),int(line[12]),int(line[13]),int(line[14]),int(line[15]))
            WhichResister(int(line[21]),int(line[22]),int(line[23]),int(line[24]),int(line[25]))

        elif int(line[0])==0 and int(line[1])==0 and int(line[2])==0 and int(line[3])==0 and int(line[4])==0 and int(line[5])==0 \
                and int(line[21])==0 and int(line[22])==0 and int(line[23])==0 and int(line[24])==0 and int(line[25])==0 : # R type instructions
             print("this is R type Instruction")
             if int(line[26])==1 and int(line[27])==0 and int(line[28])==0 and int(line[29])==0 and int(line[30])==0 and int(line[31])==0 :
                fh1.write("ADD   ")
             elif int(line[26])==1 and int(line[27])==0 and int(line[28])==0 and int(line[29])==0 and int(line[30])==0 and int(line[31])==1 :
                fh1.write("ADDU  ")
             elif int(line[26])==1 and int(line[27])==0 and int(line[28])==0 and int(line[29])==0 and int(line[30])==1 and int(line[31])==0 :
                fh1.write("SUB   ")
             elif int(line[26])==1 and int(line[27])==0 and int(line[28])==0 and int(line[29])==0 and int(line[30])==1 and int(line[31])==1 :
                fh1.write("SUBU  ")
             elif int(line[26])==1 and int(line[27])==0 and int(line[28])==0 and int(line[29])==1 and int(line[30])==0 and int(line[31])==0 :
                fh1.write("AND   ")
             elif int(line[26])==1 and int(line[27])==0 and int(line[28])==0 and int(line[29])==1 and int(line[30])==0 and int(line[31])==1 :
                fh1.write("OR    ")
             elif int(line[26])==1 and int(line[27])==0 and int(line[28])==0 and int(line[29])==1 and int(line[30])==1 and int(line[31])==0 :
                fh1.write("XOR   ")
             elif int(line[26])==1 and int(line[27])==0 and int(line[28])==0 and int(line[29])==1 and int(line[30])==1 and int(line[31])==1 :
                fh1.write("NOR   ")
             elif int(line[26])==1 and int(line[27])==0 and int(line[28])==1 and int(line[29])==0 and int(line[30])==1 and int(line[31])==0 :
                fh1.write("SLT   ")

             WhichResister(int(line[16]),int(line[17]),int(line[18]),int(line[19]),int(line[20]))
             WhichResister(int(line[6]),int(line[7]),int(line[8]),int(line[9]),int(line[10]))
             WhichResister(int(line[11]),int(line[12]),int(line[13]),int(line[14]),int(line[15]))

        elif int(line[0])==0 and int(line[1])==0 and int(line[2])==0 and int(line[3])==0 and int(line[4])==0 and int(line[5])==1 \
                and int(line[11])==0 and int(line[12])==0 and int(line[13])==0 and int(line[14])==0 and int(line[15])==1 : # BGEZ (I type) instructions
            fh1.write("BGEZ  ")
            WhichResister(int(line[6]),int(line[7]),int(line[8]),int(line[9]),int(line[10]))
            offset(int(line[16]),int(line[17]),int(line[18]),int(line[19]),int(line[20]),int(line[21]),int(line[22]),int(line[23]),int(line[24]),int(line[25]),
                   int(line[26]),int(line[27]),int(line[28]),int(line[29]),int(line[30]),int(line[31]))

        elif int(line[0])==0 and int(line[1])==0 and int(line[2])==0 and int(line[3])==1 and int(line[4])==1 and int(line[5])==1 \
                and int(line[11])==0 and int(line[12])==0 and int(line[13])==0 and int(line[14])==0 and int(line[15])==0 : # BGTZ (I type) instructions
            fh1.write("BGTZ  ")
            WhichResister(int(line[6]),int(line[7]),int(line[8]),int(line[9]),int(line[10]))
            offset(int(line[16]),int(line[17]),int(line[18]),int(line[19]),int(line[20]),int(line[21]),int(line[22]),int(line[23]),int(line[24]),int(line[25]),
                   int(line[26]),int(line[27]),int(line[28]),int(line[29]),int(line[30]),int(line[31]))

        elif int(line[0])==0 and int(line[1])==0 and int(line[2])==0 and int(line[3])==1 and int(line[4])==1 and int(line[5])==0 \
                and int(line[11])==0 and int(line[12])==0 and int(line[13])==0 and int(line[14])==0 and int(line[15])==0 : # BLEZ (I type) instructions
            fh1.write("BLEZ  ")
            WhichResister(int(line[6]),int(line[7]),int(line[8]),int(line[9]),int(line[10]))
            offset(int(line[16]),int(line[17]),int(line[18]),int(line[19]),int(line[20]),int(line[21]),int(line[22]),int(line[23]),int(line[24]),int(line[25]),
                   int(line[26]),int(line[27]),int(line[28]),int(line[29]),int(line[30]),int(line[31]))

        elif int(line[0])==0 and int(line[1])==0 and int(line[2])==0 and int(line[3])==0 and int(line[4])==0 and int(line[5])==1 \
                and int(line[11])==0 and int(line[12])==0 and int(line[13])==0 and int(line[14])==0 and int(line[15])==0: # BLTZ (I type) instructions
            fh1.write("BLTZ  ")
            WhichResister(int(line[6]),int(line[7]),int(line[8]),int(line[9]),int(line[10]))
            offset(int(line[16]),int(line[17]),int(line[18]),int(line[19]),int(line[20]),int(line[21]),int(line[22]),int(line[23]),int(line[24]),int(line[25]),
                   int(line[26]),int(line[27]),int(line[28]),int(line[29]),int(line[30]),int(line[31]))

        elif int(line[0])==0 and int(line[1])==0 and int(line[2])==0 and int(line[3])==1 and int(line[4])==0 and int(line[5])==0:
            fh1.write("BEQ   ")
            WhichResister(int(line[6]),int(line[7]),int(line[8]),int(line[9]),int(line[10]))
            WhichResister(int(line[11]),int(line[12]),int(line[13]),int(line[14]),int(line[15]))
            offset(int(line[16]),int(line[17]),int(line[18]),int(line[19]),int(line[20]),int(line[21]),int(line[22]),int(line[23]),int(line[24]),int(line[25]),
                   int(line[26]),int(line[27]),int(line[28]),int(line[29]),int(line[30]),int(line[31]))

        elif int(line[0])==0 and int(line[1])==0 and int(line[2])==0 and int(line[3])==1 and int(line[4])==0 and int(line[5])==1:
            fh1.write("BNE   ")
            WhichResister(int(line[6]),int(line[7]),int(line[8]),int(line[9]),int(line[10]))
            WhichResister(int(line[11]),int(line[12]),int(line[13]),int(line[14]),int(line[15]))
            offset(int(line[16]),int(line[17]),int(line[18]),int(line[19]),int(line[20]),int(line[21]),int(line[22]),int(line[23]),int(line[24]),int(line[25]),
                   int(line[26]),int(line[27]),int(line[28]),int(line[29]),int(line[30]),int(line[31]))

        elif int(line[0])==0 and int(line[1])==0 and int(line[2])==1 and int(line[3])==0 and int(line[4])==0 and int(line[5])==0:
            fh1.write("ADDI  ")
            WhichResister(int(line[11]),int(line[12]),int(line[13]),int(line[14]),int(line[15]))
            WhichResister(int(line[6]),int(line[7]),int(line[8]),int(line[9]),int(line[10]))
            offset(int(line[16]),int(line[17]),int(line[18]),int(line[19]),int(line[20]),int(line[21]),int(line[22]),int(line[23]),int(line[24]),int(line[25]),
                   int(line[26]),int(line[27]),int(line[28]),int(line[29]),int(line[30]),int(line[31]))

        elif int(line[0])==0 and int(line[1])==0 and int(line[2])==1 and int(line[3])==0 and int(line[4])==0 and int(line[5])==1:
            fh1.write("ADDIU  ")
            WhichResister(int(line[11]),int(line[12]),int(line[13]),int(line[14]),int(line[15]))
            WhichResister(int(line[6]),int(line[7]),int(line[8]),int(line[9]),int(line[10]))
            offset(int(line[16]),int(line[17]),int(line[18]),int(line[19]),int(line[20]),int(line[21]),int(line[22]),int(line[23]),int(line[24]),int(line[25]),
                   int(line[26]),int(line[27]),int(line[28]),int(line[29]),int(line[30]),int(line[31]))

        elif int(line[0])==0 and int(line[1])==0 and int(line[2])==1 and int(line[3])==0 and int(line[4])==1 and int(line[5])==0:
            fh1.write("SLTI  ")
            WhichResister(int(line[11]),int(line[12]),int(line[13]),int(line[14]),int(line[15]))
            WhichResister(int(line[6]),int(line[7]),int(line[8]),int(line[9]),int(line[10]))
            offset(int(line[16]),int(line[17]),int(line[18]),int(line[19]),int(line[20]),int(line[21]),int(line[22]),int(line[23]),int(line[24]),int(line[25]),
                   int(line[26]),int(line[27]),int(line[28]),int(line[29]),int(line[30]),int(line[31]))

        elif int(line[0])==1 and int(line[1])==0 and int(line[2])==1 and int(line[3])==0 and int(line[4])==1 and int(line[5])==1:
            fh1.write("SW    ")
            WhichResister(int(line[11]),int(line[12]),int(line[13]),int(line[14]),int(line[15]))
            offset(int(line[16]),int(line[17]),int(line[18]),int(line[19]),int(line[20]),int(line[21]),int(line[22]),int(line[23]),int(line[24]),int(line[25]),
                   int(line[26]),int(line[27]),int(line[28]),int(line[29]),int(line[30]),int(line[31]))
            base(int(line[6]),int(line[7]),int(line[8]),int(line[9]),int(line[10]))

        elif int(line[0])==1 and int(line[1])==0 and int(line[2])==0 and int(line[3])==0 and int(line[4])==1 and int(line[5])==1:
            fh1.write("LW    ")
            WhichResister(int(line[11]),int(line[12]),int(line[13]),int(line[14]),int(line[15]))
            offset(int(line[16]),int(line[17]),int(line[18]),int(line[19]),int(line[20]),int(line[21]),int(line[22]),int(line[23]),int(line[24]),int(line[25]),
                   int(line[26]),int(line[27]),int(line[28]),int(line[29]),int(line[30]),int(line[31]))
            base(int(line[6]),int(line[7]),int(line[8]),int(line[9]),int(line[10]))

        elif int(line[0])==0 and int(line[1])==0 and int(line[2])==0 and int(line[3])==0 and int(line[4])==1 and int(line[5])==0:
            fh1.write("J     ")
            index(int(line[6]),int(line[7]),int(line[8]),int(line[9]),int(line[10]),int(line[11]),int(line[12]),int(line[13]),int(line[14]),int(line[15]),
                   int(line[16]),int(line[17]),int(line[18]),int(line[19]),int(line[20]),int(line[21]),int(line[22]),int(line[23]),int(line[24]),int(line[25]),
                   int(line[26]),int(line[27]),int(line[28]),int(line[29]),int(line[30]),int(line[31]))


        fh1.write("\n")

except (IOError, OSError) as err:
    print(err)

finally:
    if fh is not None:
       fh.close()
    if fh1 is not None:
       fh1.close()
