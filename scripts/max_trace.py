#Created by: Kurt Wimer
#outputs the maximum value found in the csv file trace.csv

import csv
def main():
    with open('trace.csv','r') as f:
        max =0
        count = 0
        reader = csv.reader(f);
        for row in reader:
            count = count+1
            if (count >100000):
                break
            if int(row[4])>max:
                max = int(row[4])
    print(max)

main()
