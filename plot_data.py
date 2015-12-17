#!/usr/bin/python

import sys
import os.path
import pandas as pd
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

print 'Number of arguments:', len(sys.argv), 'arguments.'
print 'Argument List:', str(sys.argv)

#check if command line file actually exists
file_name = sys.argv[1]
if  not os.path.isfile(file_name):
    print "File does not exist!"
    sys.exit(1)

#open file and add header to later access the values
df = pd.read_csv(file_name, header=None, names = ['x', 'y', 'z'])

#create numpy arrays without duplicates
x_vals = np.unique(df['x'])
y_vals = np.unique(df['y'])

#create 2D array of iteration numbers('z')
z_t = df['z']
z_vals = np.reshape(z_t, (len(x_vals),len(y_vals))).T


figu = plt.figure(1, figsize=(12,9))
plt.pcolormesh(x_vals,y_vals,z_vals, cmap=plt.cm.hot)
plt.colorbar()

#obtain same file name but different extension (.csv -> .jpg)
import os
pic_file = os.path.splitext(file_name)[0]+'.jpg'

#save figure to a .jpg file since can't plot to screen
figu.savefig(pic_file)
