#Created by Kurt Wimer
#Extracts the first n block numbers from SNIA's Microsoft Cambridge traces
#if having trouble reading the file open it with a spreadsheet editor and export to csv again to get standard format

import csv
def main():
    count = 0    
    with open('trace.csv','r') as f:
        reader = csv.reader(f);
        for row in reader:
            count = count+1
            if (count>500000): #how many blocks do you want?
                 break
            print(row[4])

main()

