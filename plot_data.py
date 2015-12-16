#!/usr/bin/python

import sys
import os.path
import pandas as pd
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

print 'Number of arguments:', len(sys.argv), 'arguments.'
print 'Argument List:', str(sys.argv)


file_name = sys.argv[1]
if os.path.isfile(file_name) == True:
    print "File does no exist!"
    sys.exit(1)

<<<<<<< HEAD
df = pd.DataFrame.from_csv(file_name)
df.columns['x', 'y', 'z']
=======
df = pd.DataFrame.from_csv(file_name, columns=['x', 'y', 'z'])
>>>>>>> f82e934e205bfb47180257aa8cddaa9332c6c84f

x_t = df['x']
x_vals = []
for i in x_t:
    if i not in x_vals:
          x_vals.append(i)

y_t = df['y']
y_vals = []
for i in y_t:
    if i not in y_vals:
          y_vals.append(i)

z_t = df['z']
<<<<<<< HEAD
z_vals = np.reshape(z_t, (len(x_vals),len(y_vals))).T
=======
z_vals = np.reshape(z_t, (len(x_vals),len(y_vals)).T
>>>>>>> f82e934e205bfb47180257aa8cddaa9332c6c84f

fig = plt.figure(1, figsize=(12,9))
plt.pcolormesh(x_vals,y_vals,z_vals, cmap=plt.cm.hot)
plt.colorbar()

fig.savefig("./mandelbrot.jpg")