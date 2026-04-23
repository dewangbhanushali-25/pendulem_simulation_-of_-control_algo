import pandas as pd
import matplotlib.pyplot as plt

# Load data
data = pd.read_csv("log.csv")

# Plot theta (angle)
plt.figure()
plt.plot(data["time"], data["theta"])
plt.xlabel("Time (s)")
plt.ylabel("Theta (rad)")
plt.title("Cart-Pole (No Control)")
plt.grid()

# Plot cart position
plt.figure()
plt.plot(data["time"], data["x"])
plt.xlabel("Time (s)")
plt.ylabel("Cart Position (m)")
plt.title("Cart Position")
plt.grid()

plt.show()