import matplotlib.pyplot as plt
import numpy as np
import matplotlib.ticker as mtick

response= raw_input("Is this code in the same directory where the input textfile is? (Y/N): ")
if response=='N':
	print "Please copy the code to the data file's directory, then try again"
	quit()
	
#Read the textfile as string data. This is helpful when one has mixed format data file
f = raw_input("Enter the name of the textfile including the extension:")

date = raw_input("Enter date of cool down test (e.g. 30 May 2018): ")
print date

data = np.loadtxt(f)

print(data[1,:])

#Convert strings to usable float data 

#data = np.asfarray(data,float)

# The data is x, x', y, y' P, E, entry #

#########################################################
# Plot target y distribution histogram
#########################################################

fig1=plt.figure()
 
ax1=fig1.add_subplot(111)

#Plot the data without normalizing it
nbins=100
result=plt.hist(data[:,0], range=[-1.5, 1.5], color='white', edgecolor='blue', bins=nbins, histtype="step", linewidth=2)

"""
#Find min and max of xticks so we know where we should compare 
#theoretical dist.

#xt = plt.xticks()[0]  
xmin, xmax = 20.62, 20.72  
lnspc = np.linspace(xmin, xmax, len(temp_filter))

# Fit normal distribution 
m, s = stats.norm.fit(temp_filter) # get mean and standard deviation  
pdf_g = stats.norm.pdf(lnspc, m, s) # now get theoretical values in our interval 

#Scale norm fit to data and plot
dx=result[1][1]-result[1][0] # this gives the width of a single bar, in Kelvin
scale=len(temp_filter)*dx

ax1.plot(lnspc, pdf_g*scale, '--r', label="Mean=%.2fK \n $\sigma$=%.2fK" %(m, s), linewidth=3) # plot it
"""

#Title and labels
ax1.set_title('Pion source dist.', size = 15)
ax1.set_xlabel('x (mm)', size = 13)

#Show legend
leg = ax1.legend(loc=1, fontsize=12)

plotname1 = 'x_Dist_ProdTar_g4_in'
plotname1 += date
plotname1 +='.png'

plt.savefig(plotname1, bbox_inches='tight')


