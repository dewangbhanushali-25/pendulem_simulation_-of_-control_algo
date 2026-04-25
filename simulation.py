import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("log.csv")

plt.figure()
plt.plot(data["time"], data["theta"])
plt.xlabel("Time (s)")
plt.ylabel("Theta (rad)")
plt.title("Cart-Pole (No Control) — RK4")
plt.grid()

plt.figure()
plt.plot(data["time"], data["x"])
plt.xlabel("Time (s)")
plt.ylabel("Cart Position (m)")
plt.title("Cart Position — RK4")
plt.grid()

plt.show()