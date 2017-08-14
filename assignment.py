#!/usr/bin/env python3
#Python Script to complete whole Computing Assignment for FINS3625
#Written by Alick Yang
import openpyxl

#Functions for Questions
#Question 1
def q1(sheet, loRange, hiRange, col, cell):
    #determining which cell
    if col == 2:
        column = 'B'
    elif col == 3:
        column = 'C'
    #loop
    for i in range(loRange, hiRange):
        #Updates everything for Column D
        val = '=' + column + str(i) + '-' + column + str(i-1)
        sheet[cell+str(i)].value = val

#Question 2
def q2(sheet, loRange, hiRange, col, cell):
    #determining which cell
    if col == 2:
        column = 'D'
    elif col == 3:
        column = 'E'
    #loop
    for i in range(loRange, hiRange):
        stdev = '=STDEV(' + column + str(i+1) + ',' + column + str(i) + ')'
        sheet[cell+str(i)] = stdev

#End Functions

#Main
#open up excel sheet
wb = openpyxl.load_workbook('Oil-Futures-Data-2017-2.xlsx')
wb.get_sheet_names()
#Get data stored in sheet 1
sheet = wb.get_sheet_by_name('Sheet1')

#Question 1
q1(sheet, 4, 525, 2, 'D');
q1(sheet, 4, 525, 3, 'E');
#Question 2
q2(sheet, 4, 525, 2, 'F');
q2(sheet, 4, 525, 3, 'G');

#Finish and Save
wb.save('Oil-Futures-Data-2017-2.xlsx')
