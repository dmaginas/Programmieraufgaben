romanDgts= 'ivxlcdmVXLCDM_'
 
def ToRoman(num):
   namoR = ''
   if num >=4000000:
      print ('Too Big -')
      return '-----'
   for rdix in range(0, len(romanDgts), 2):
      if num==0: break
      num,r = divmod(num,10)
      v,r = divmod(r, 5)
      if r==4:
         namoR += romanDgts[rdix+1+v] + romanDgts[rdix]
      else:
         namoR += r*romanDgts[rdix] + (romanDgts[rdix+1] if(v==1) else '')
   return namoR[-1::-1]
   
if __name__ == "__main__": 
  test = (1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,30,40,50,60,69,70,
     80,90,99,100,200,300,400,500,600,666,700,800,900,1000,1009,1444,1666,1945,1997,1999,
     2000,2008,2500,3000,4000,4999,5000,6666,10000,50000,100000,500000,1000000);
  for val in test: 
    print (val, ToRoman(val))