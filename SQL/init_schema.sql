CREATE TABLE "People" (
    "Login" VARCHAR(50) PRIMARY KEY,
    "Password" VARCHAR(50) NOT NULL,
    "Age" INT,
    "Growth" INT,
    "Target_waight" INT,
    "Intensity" VARCHAR(20),
    "Sex" VARCHAR(10),
    "Number_phone" VARCHAR(15)
);

CREATE TABLE "Exercise" (
    "Exercise_ID" SERIAL PRIMARY KEY,
    "Name_of_exercise" VARCHAR(100) NOT NULL,
    "Kalories" INT NOT NULL,
    "Reps" VARCHAR(20),
    "Time_minutes" INT
);

CREATE TABLE "Body" (
    "ID_process" SERIAL PRIMARY KEY,
    "Login" VARCHAR(50),
    "Weight" INT,
    "Chest_size" INT,
    "Back_size" INT,
    "Leg_size" INT,
    "Arm_size" INT,
    "Workout" TEXT,
    "Calories_burned" INT,
    "Data" TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    CONSTRAINT fk_user FOREIGN KEY("Login") REFERENCES "People"("Login") ON DELETE CASCADE
);

INSERT INTO "Exercise" ("Name_of_exercise", "Kalories", "Reps", "Time_minutes") VALUES
('Push-ups', 10, '15', 2),
('Squats', 15, '20', 3),
('Running', 100, 'N/A', 10),
('Plank', 5, '60 sec', 1),
('Lunges', 12, '15 per leg', 4),
('Burpees', 20, '10', 2),
('Jumping Jacks', 15, '50', 2),
('Crunches', 8, '20', 3),
('Pull-ups', 15, '10', 2);