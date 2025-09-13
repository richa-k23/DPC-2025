coins = list(map(int, input("Enter the coin denominations: ").split()))
amount = int(input("Enter the amount: "))
dp = [float('inf')] * (amount + 1)
dp[0] = 0
for i in range(1, amount + 1):
    for coin in coins:
        if i - coin >= 0:
            dp[i] = min(dp[i], dp[i - coin] + 1)
if dp[amount] == float('inf'):
    print("Minimum coins required: ",-1)
else:
    print("Minimum coins required: ",dp[amount])