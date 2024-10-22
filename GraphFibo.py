import json
import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np
    
f = open('data.json')
data = json.load(f)
x = data['x']
y = data['y']
a = data['a']
np.seterr(all='ignore', divide='ignore', over='ignore', under='ignore', invalid='ignore')

def FiboGraph():
    fig, ax1 = plt.subplots()
    
    ax1.plot(x,a)
    ax1.set_xlabel('iteration')
    ax1.set_ylabel('value')
    ax1.set_yscale('log')
    ax1.set_xscale('log')
    plt.show()
    
    print(a)
    
FiboGraph()

f.close()