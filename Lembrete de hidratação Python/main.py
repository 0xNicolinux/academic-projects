import time
import json
import random
from notifypy import Notify

def coletar_dados_usuario():
    print("=== Avaliação de Hidratação ===\n")
    nome = input("Qual é o seu nome? ")
    massa_corporal = float(input("Qual é a sua massa corporal em kg? "))

    print("\nNível de atividade física:")
    print("[1] - Sedentário")
    print("[2] - Moderadamente ativo")
    print("[3] - Ativo")

    nivel_atividade_fisica = input("Selecione o número correspondente ao seu perfil de atividade física: ")

    if nivel_atividade_fisica == "1":
        ml_por_kg = 30
    elif nivel_atividade_fisica == "2":
        ml_por_kg = 35
    elif nivel_atividade_fisica == "3":
        ml_por_kg = 40
    else:
        ml_por_kg = 35  

    total_agua_dia = massa_corporal * ml_por_kg
    litros_dia = total_agua_dia / 1000 

    necessidade_hidrica = f"Você precisa de {litros_dia:.1f} litros de água por dia.\n"
    return nome, necessidade_hidrica

def lembrete(nome, necessidade_hidrica):
    with open("data/hydration_phrases.json", "r", encoding="utf-8") as arquivo_json:
        dados_json = json.load(arquivo_json) 

    lista_frases_hidratacao = dados_json["frases_hidratacao"]
            
    nome_usuario = f"{nome}, é hora de beber água!"
    message = random.choice(lista_frases_hidratacao)
    
    notification = Notify()
    notification.application_name = "Lembrete de Hidratação"
    notification.title = nome_usuario
    notification.message = f"{necessidade_hidrica}\n{message}"
    notification.icon = "media/image/drinking-water-icon.png"
    notification.audio = "media/audio/notify.wav"
    notification.send()

nome, necessidade_hidrica = coletar_dados_usuario()

while True:
    lembrete(nome, necessidade_hidrica)
    time.sleep(60 * 60)  