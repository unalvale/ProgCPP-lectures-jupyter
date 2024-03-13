import matplotlib.pyplot as plt
import numpy as np

h, f, c, rf, rc = np.genfromtxt('datos.txt', unpack=True) 
plt.loglog(h, f, '-o', label="f")
plt.loglog(h, c, '-s', label="c")
plt.loglog(h, rf, '-*', label="rf")
plt.loglog(h, rc, '-^', label="rc")
plt.legend()
plt.savefig("plot-python.pdf")