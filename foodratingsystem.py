def show_menu():
    print("\n=== Food Rating System ===")
    print("1. Add a food rating")
    print("2. View all ratings")
    print("3. Show highest rated food")
    print("4. Exit")


def main():
    ratings = {}  # dictionary {food: rating}

    while True:
        show_menu()
        choice = input("Enter your choice (1-4): ")

        if choice == "1":
            food = input("Enter food name: ").capitalize()
            try:
                rating = float(input("Enter rating (1 to 5): "))
                if 1 <= rating <= 5:
                    ratings[food] = rating
                    print(f"✅ {food} rated {rating}/5 added successfully!")
                else:
                    print("⚠ Rating must be between 1 and 5.")
            except ValueError:
                print("⚠ Please enter a valid number.")

        elif choice == "2":
            if ratings:
                print("\n📋 Food Ratings:")
                for food, rate in ratings.items():
                    print(f"- {food}: {rate}/5")
            else:
                print("⚠ No ratings yet.")

        elif choice == "3":
            if ratings:
                best_food = max(ratings, key=ratings.get)
                print(f"🏆 Highest rated: {best_food} ({ratings[best_food]}/5)")
            else:
                print("⚠ No ratings yet.")

        elif choice == "4":
            print("👋 Exiting Food Rating System. Goodbye!")
            break

        else:
            print("⚠ Invalid choice, try again.")


if __name__ == "__main__":
    main()
