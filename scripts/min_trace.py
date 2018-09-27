#Created by Kurt Wimer
#Outputs the minimum value found in csv file trace.csv


import csv
def main():
    with open('trace.csv','r') as f:
        min =999999999999 #if minimum is larger than this you should be using a less lazily coded script
        count = 0
        reader = csv.reader(f);
        for row in reader:
            count = count+1
            if (count >100000):
                break
            if int(row[4])<min:
                min = int(row[4])
    print(min)

main()
