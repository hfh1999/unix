#!/bin/bash
fpath='/home/flyer/Work/C/unix/'
i=2
count=0
for i in $(ls |grep -v count.sh )
do
    for cfile in $(ls $fpath/$i/*.c)
    do
        count=$(($count + $(cat $cfile |wc -l)))
    done
done
echo "The number of lines is $count"
