

#Q1
if [ "$#" -ne 2 ] ; then
  echo "Usage: Input 2 file names."
  exit 1
fi

#Q2
if ! [ -f "$1" ]; then
    echo "File $1 doesn't exist."
    exit 1
fi

>$2

#Q3
awk -F, 'NR>1 {print $1,$2,$3,$5,$6,$7,$10,$11}' $1 >> $2

echo "----------------------------------------------------" >> $2

#Q4
awk -F, '$3=="Bachelor\x27s" {print $1}' $1 >> $2

echo "----------------------------------------------------" >> $2
echo "Geography : Average Admission Rate" >> $2
awk -F, 'NR>1 {A[$6]++;sum[$6]+=$7} END{for(i in A) print i,":",sum[i]/A[i]}' $1 >> $2

echo "----------------------------------------------------" >> $2

#Q6
sort -t , -nr -k 16 $1 | awk -F, 'NR<=5 {print $1}' >> $2
echo "----------------------------------------------------" >> $2


